#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= n ; j++){
            if(i == j) cout << "*";
            else cout << "	";
        } cout << endl;
    }   
}
