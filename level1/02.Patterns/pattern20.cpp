#include <iostream>
using namespace std;
int main(int argc, char**argv){
    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(j == 1 || j == n)
                cout << "*  ";
            else if(i>=n/2 + 1 && (i == j || n - i + 1 == j)){
                cout << "*  ";
            }
            else 
                cout << "   ";
        }
        cout << endl;
    }
}