#include <iostream>
using namespace std;
int main(int argc, char**argv){
    int n;
    cin >> n;

    int sp = n/2 , st = 1;
    for(int i = 1 ; i <= n ; i++){
        if(i == n/2+1){
            for(int j = 1 ; j <= sp ; j++){
                cout <<"*	";
            }
        }

        if(i != n/2+1)
        for(int j = 1 ; j <= sp ; j++){
            cout << "	";
        }
        for(int j = 1 ; j <= st ; j++){
            cout << "*	";
        }

        if(i <= n/2){
            st++;
        } else {
            st--;
        }
        cout << endl;
    }
}
