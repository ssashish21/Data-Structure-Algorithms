/*Breadth-First Search (BFS) is a Graph Traversal Algorithm for traversing or searching tree
or graph data structures.
Application:
    1. Find the shortest path from a source to other vertices in an unweighted graph.
    2. Finding a solution to a problem or a game with the least number of moves, if each state
       of the game can be represented by a vertex of the graph, and the transitions from one state 
       to the other are the edges of the graph.
    
    
BFT(Breadth-First Traverse):
input:  6 6 <- number of nodes & edges
        1 2 
        1 3
        2 5
        2 4
        4 5
        5 6
        2   <- starting vertex
output: 2 1 5 4 3 6 
*/
#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define qi queue<int>
using namespace std;

int nodes;   // globally, used in bfs function to make dynamic visited array                       
void bfs( vi G[] , int start){
        vi visited( nodes , 0 );    
        qi q;     
        visited[start] = 1;
        q.push(start); 
        
         while(!q.empty()){
              start = q.front();
              cout<<start<<" ";
              q.pop(); 
               for (auto adjacent = G[start].begin(); adjacent != G[start].end(); adjacent++)
                         if (!visited[*adjacent]) {
                                visited[*adjacent] = 1;
                                q.push(*adjacent); 
                             } 
         } 
}
int main(){
        int edges , x , y, start;
        cin>>nodes>>edges;
        nodes+=1;
        vi G[nodes];
        for(int i = 0;i < edges ; ++i){
                cin >> x >> y;
                G[x].pb(y);
                G[y].pb(x);
            }
            cin>>start;
        bfs(G , start);
    return 0;
}
