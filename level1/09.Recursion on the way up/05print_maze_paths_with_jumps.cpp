#include<iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
    if(sr == dr && sc == dc){
        cout  << psf << endl;
        return;
    }
    if(sr > dr || sc > dc) return;
    for(int mj = 1 ; mj <= dc - sc ; mj++){
        string jump(1 , (mj + '0'));
        printMazePaths(sr , sc + mj , dr , dc , psf + "h" + jump);
    }
    
    for(int mj = 1 ; mj <= dr - sr ; mj++){
        string jump(1 , (mj + '0'));
        printMazePaths(sr + mj , sc , dr , dc , psf + "v" + jump);
    }
    
    for(int mj = 1 ; mj <= dc - sc && mj <= dr - sr ; mj++){
        string jump(1 , (mj + '0'));
        printMazePaths(sr + mj  , sc + mj , dr , dc , psf + "d" + jump);
    }    
}
int main() {
    int n ;
    int m ;
    cin>>n>>m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}