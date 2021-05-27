#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;

    int st = n/2 + 1 , sp = 1;
    for(int i = 1 ; i <= n ; i++){

        for(int j = 1 ; j <= st ; j++){
            cout <<"*	";
        }
        for(int j = 1 ; j <= sp ; j++){
            cout << "	";
        }
        for(int j = 1 ; j <= st ; j++){
            cout <<"*	";
        }
        
        if(i <= n/2){
            sp+=2;
            st--;
        } else {
            sp-=2;
            st++;
        }
        cout << endl;
    }   
}
