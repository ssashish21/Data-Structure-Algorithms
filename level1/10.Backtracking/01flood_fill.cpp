#include<iostream>
#include<vector>
using namespace std;

int n , m;
void floodfillHelper(vector<vector<int>> maze , int i , int j , string res){
    //reach bottom right corner print res
    if(i == n - 1 && j == m - 1){
        cout << res << endl;
        return;
    }

    //out of the maze
    if(i < 0 || j < 0 || i == n || j == m || maze[i][j] == 1){
        return;
    }

    maze[i][j] = 1;
    floodfillHelper(maze , i - 1 , j , res + 't');
    floodfillHelper(maze , i , j - 1 , res + 'l');
    floodfillHelper(maze , i + 1 , j , res + 'd');
    floodfillHelper(maze , i , j + 1 , res + 'r');
    maze[i][j] = 0;
}

void floodfill(vector<vector<int>> maze) {
    int n = maze.size();
    int m = maze[0].size();

	floodfillHelper(maze , 0 , 0 , "");
}

int main() {
    cin >> n >> m;
    vector<vector<int>> arr(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    floodfill(arr);
}