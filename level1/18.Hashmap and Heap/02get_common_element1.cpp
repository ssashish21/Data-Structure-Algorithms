#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n1 , n2;
    cin >> n1;
    int ar1[n1];
    for(int i = 0 ; i < n1 ; i++) 
        cin >> ar1[i];

    cin >> n2;
    int ar2[n2];
    for(int i = 0 ; i < n2 ; i++)
        cin >> ar2[i];

    unordered_map<int , bool> ump;
    for(int n : ar1) ump[n] = true;

    for(int n : ar2){
        if(ump[n] == true){
            cout<<n<<endl;
            ump[n] = false;
        }
    }
}