/*
The Knapsack Problem is a famous Dynamic Programming Problem that falls in the optimization category.
It derives its name from a scenario where, given a set of items with specific weights and assigned 
values, the goal is to maximize the value in a knapsack while remaining within the weight constraint.

Each item can only be selected once, as we don’t have multiple quantities of any item.



Let’s take the example of Mary, who wants to carry some fruits in her knapsack
and maximize the profit she makes. She should pick them such that she minimizes
weight (<=bag​′s capacitycapacity) and maximizes profit value.

Here are the weights and profits associated with the different fruits:
Number of items: 4
Items: { Apple, Orange, Banana, Melon }
Weights: { 2, 3, 1, 4 }
Profits: { 4, 5, 3, 7 }
Knapsack Capacity: 5

o/p: 10 (Fruits picked by marry: banana + melon,she got max profit and the 
     weight of items <= knapsack capacity)

*/

/* Recursive solution:

int knapsack(vi &weight,vi &profit,int capacity,int n){
    //if knapsack is empty / no space or
    //there is no item to pick
    if(capacity == 0 || n == 0)
        return 0;

    //if there is space for current item
    //we can  either pick that item or move to next
    //and return the max profit 
    if(capacity >= weight[n-1])
        return max(profit[n-1] + knapsack(weight,profit,capacity-weight[n-1],n-1) ,knapsack(weight,profit,capacity,n-1));
    
    //weight of current item is greater
    //than current knapsack capacity
    //skip that item
    else
        return knapsack(weight,profit,capacity,n-1);

}
In the recursive solution there may occure stack overflow condition and our program stops.
Or sometime it take to much time to compute all the values and our program may end up with
TLE(Time Limit Exceed), most of the time competative programers face this problem.

MEMOIZATION is the best method to overcome this type of situation.


*/

/*
MEMOIZATION:
Time  : O(capacity*number of items)
      : O(n^2)
Space : O(n^2)

Overlaping subproblem arise in every recursive solution if the there are two or more branches
of every nodes in recursion tree.

                                (n)
                                / \
                               /   \
                              /     \
                         (n-1)        (n-2)
                        / \             / \
                       /   \           /   \
                      /     \         /     \
                 (n-2)     (n-3)    (n-3)  (n-4)

In the above diagram one recursive function is calling for two different values of n
And we observe overlaping starts from level 2.

To overcome this type of situation we store the computed values in any
data structure(generally array is used) so further we restore that value
from array in O(1) time.
This method is basically called memoization.

Defination: In computing, memoization or memoisation is an optimization technique used primarily to
            speed up computer programs by storing the results of expensive function calls and returning
            the cached result when the same inputs occur again. 

*/

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 1005
int dp[MAX][MAX];

void filldp(){
    for(int i = 0 ; i < MAX ; i++)
        for(int j = 0 ; j < MAX ; j++)
            dp[i][j] = -1;
}

int knapsack(vi &weight,vi &profit,int capacity,int n){
    if(capacity == 0 || n == 0)
        return 0;
    
    if(dp[capacity][n] != -1)
        return dp[capacity][n];

    if(capacity >= weight[n-1])
        dp[capacity][n] = max(profit[n-1] + knapsack(weight,profit,capacity-weight[n-1],n-1) ,knapsack(weight,profit,capacity,n-1));
    
    else
        return dp[capacity][n] = knapsack(weight,profit,capacity,n-1);

}

int main(){
    int n =4;
    vi weight= {2,3,1,4};
    vi profits= {4,5,3,7};
    int capacity = 5;
    filldp();
    cout<<knapsack(weight,profits,capacity,n);
    return 0;
}

/*
We can further optimize the space compelxity of this problem by using Top down approach.
Top down method / Real Dynamic Programing

> Potential to transform exponential-time brute-force solutions into polynomial-time algorithms.
> Much more efficient because its iterative
*/