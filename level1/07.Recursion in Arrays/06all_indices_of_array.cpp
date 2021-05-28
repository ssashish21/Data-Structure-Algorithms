#include<iostream>
using namespace std;
int c = 0;
void solve(int ar[] ,int si ,  int n , int x){
    if(si == n) return;
    if(ar[si] == x) cout << si << endl , c = c + 1;
    solve(ar , si + 1 , n , x);
}
int main(){
    int n; cin >> n;
    int ar[n];
    for(int i = 0 ; i < n ; i++) cin >> ar[i];
    int x ; cin >> x;
    solve(ar ,0, n , x);
    if(c == 0) cout << " ";
}
