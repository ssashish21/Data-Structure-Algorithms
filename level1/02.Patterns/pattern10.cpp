#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;

    int ls = n/2+1 , rs = n/2+1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= n ; j++){
            if(j == ls || j == rs) cout << "*	";
            else cout << "	";
        }
        if(i <= n/2){
            ls--;
            rs++;
        } else {
            ls++;
            rs--;
        }
        // cout << ls << " " << rs << endl; 
        cout << endl;
    }   
}
