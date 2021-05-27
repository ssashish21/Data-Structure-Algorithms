#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int icj = 1;
        for(int j = 0; j <= i ; j++){
            cout << icj <<"	";
            int icjp1 = icj * (i-j) / (j + 1);
            icj = icjp1;
        }
        // cout << ls << " " << rs << endl; 
        cout << endl;
    }   
}
