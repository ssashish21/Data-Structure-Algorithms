#include <iostream>
using namespace std;
int main(int argc, char**argv){
    int n;
    cin >> n;

    int sp = n/2 , num = 1 , sc = 1;
    for(int i = 1 ; i <= n ; i++){

        int c = sc;
        
        for(int j = 1 ; j <= sp + num ; j++){
            if(j <= sp) cout << "	";
            else{
                if(j <= n/2) cout << c++ << "	";
                else cout <<c-- <<"	";
            }
        }
        
        if(i <= n/2){
            sp--;
            num+=2;
            sc++;
        } else {
            sp++;
            num-=2;
            sc--;
        }
        cout << endl;
    }
    
}
