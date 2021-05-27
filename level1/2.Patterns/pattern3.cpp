#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;

    int sp = n-1 , st = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= sp ; j++){
            cout <<"	";
        }
        for(int j = 1 ; j <= st ; j++){
            cout << "*	";
        }
        sp--;
        st++;
        cout << endl;
    }   
}
