#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;

    int sp = n/2 , st = 1;
    for(int i = 1 ; i <= n ; i++){

        for(int j = 1 ; j <= sp ; j++){
            cout <<"	";
        }
        for(int j = 1 ; j <= st ; j++){
            cout << "*	";
        }
        for(int j = 1 ; j <= sp ; j++){
            cout <<"	";
        }
        
        if(i <= n/2){
            sp--;
            st += 2;
        } else {
            sp++;
            st -= 2;
        }
        cout << endl;
    }   
}
