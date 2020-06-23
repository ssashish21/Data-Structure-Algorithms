// Convex HULL / Jarvi's March Algorithm or Wrapping
// Summary: Implimentation of Jarvis Algorithm to compute 
// the convex hull of aset of point in the xy-plane
// Input: A set of points in the xy-plane
// Output: Set of points containing the upper convex hull of the input

//key idea : First find the left most point on the 2D plane
//           Starting from the left most point, we keep the point in convex hull by counterclockwise rotation.
//           From a current point, we can choose the next point by checking the orientations of those points
//           from the current point. When the angle is largest, the point is chosen(Right hand Thumb rule).
//           After completing all points, when the next point is the start point, stop the algorithm.

//Analysis
//Time complexity : O(n(number of point) * m(points on convex hull))
//                : In the wrost case senario when m = n , TC is O(n^2)
//Space Complexity: O(n)



#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define Point vector<pair<int,int>>
#define point pair<int,int>
#define endl '\n'

// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(point p, point q, point r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0; // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 

Point convexHull(Point &points){
    int n = points.size();
    //must be atleat 3 point
    if(n < 3) return Point {}; 

    Point hull;

    //find the leftmost point
    int l = 0;
    for(int i = 1 ; i < n ; i++){
        if(points[i].x < points[l].x)
            l = i;
    }

    //start from the left most point ,keepmoving counterclockwise
    //until reach the starting point again. The loop rus O(h) times
    //where h is the number of points in result
    int p = l;
    int q;
    do{
        //current point
        hull.pb(mp(points[p].x,points[p].y));

        // Search for a point 'q' such that orientation(p, x, 
        // q) is counterclockwise for all points 'x'. The idea 
        // is to keep track of last visited most counterclock- 
        // wise point in q. If any point 'i' is more counterclock- 
        // wise than q, then update q.

        q = (p+1)%n;
        for(int i = 0 ; i < n ; i++){
            if(orientation(points[p],points[i],points[q]) == 2)
                q = i;
        }

        p = q;

    }while(p!=l);

return hull;
}
int main() {	
    Point points = {{0, 3}, {2, 2}, {1, 1}, {2, 1},{3, 0}, {0, 0}, {3, 3}};
    Point hull = convexHull(points);
    for(int i = 0 ; i< hull.size() ; i++){
        cout<<hull[i].x<<" "<<hull[i].y<<endl;
    }
    return 0;
}

// Time complexity can be further optimized to O(nlogn) by using Graham's scan Algorithm
