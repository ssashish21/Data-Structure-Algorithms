#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;

    int c = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= i ; j++){
            cout << c++ <<"	";
        }
        // cout << ls << " " << rs << endl; 
        cout << endl;
    }   
}
