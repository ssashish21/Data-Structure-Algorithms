#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    if(str.size() == 0){
        cout << asf << endl;
        return;
    }
    for(int i = 0 ; i < str.size() ; i++){
        string l = str.substr(0 , i);
        string r = str.substr(i + 1);
        printPermutations(l + r , asf + str[i]);
    }
}
int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}