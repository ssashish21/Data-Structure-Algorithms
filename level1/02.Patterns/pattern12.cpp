#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;

    int a = 0 , b = 1 , c = 0;
    cout<<"0
";
    for(int i = 2 ; i <= n ; i++){
        for(int j = 1; j <= i ; j++){
            if(i == 2 && j == 1){
                cout <<"1	";
                continue;
            }
            cout << a + b<<"	";
            c = a + b;
            a = b;
            b = c;
        }
        // cout << ls << " " << rs << endl; 
        cout << endl;
    }   
}
