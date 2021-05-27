#include <iostream>
using namespace std;
int main(int argc, char**argv){
    int n;
    cin >> n;

    int s = 1 , e = 1 , sp = n * 2 - 3;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++){
            cout << s++ << "	";
        }   
        for(int j = 1 ; j <= sp ; j++){
            cout << "	";
        } 
        for(int j = 1 ; j <= i ; j++){
            if(i == n && j == 1){
                e--;
                continue;
            }
            cout << e-- << "	";             
        }
        
        s = 1;
        e = i+1;
        sp-=2;
        cout << endl;
    }
}
