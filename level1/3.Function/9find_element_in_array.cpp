#include<iostream>
using namespace std;


int main(){
    //write your code here
    
    int n , d;
    cin >> n;
    int ar[n];
    for(int i = 0 ; i < n ; i++){
        cin >> ar[i];
    }
    cin >> d;
    for(int i = 0 ; i < n ; i++){
        if(d == ar[i]){
            cout <<i;
            return 0;
        }
    }
    cout<<-1;
}