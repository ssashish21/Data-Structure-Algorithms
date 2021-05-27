#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    int st = n , sp = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= sp ; j++){
            cout <<"	";
        } 
        for(int j = 1 ; j <= st ; j++){
            cout << "*	";
        }
        st--;
        sp++;
        cout << endl;
    }
    //write your code here

}
