#include<iostream>
#include<cstring>
#include<string>
using namespace std;
static string keypad[] = {".;" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tu" , "vwx" , "yz"};
void printKPC(string num , string output){
     if(num.length() == 0){
        cout<<output<<endl;
        return;
    }
    for(int i = 0 ; i < keypad[num[0] - '0'].size() ; i++)
        printKPC(num.substr(1) , output + keypad[num[0] - '0'][i]);

   
}
int main(){
    string s; cin>>s;
    printKPC(s, "");
    return 0;
}