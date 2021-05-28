#include<iostream>
#include<cstring>
#include<string>

using namespace std;
void printEncodings(string s , string coding){
    if(s.empty()){
        cout<<coding<<endl;
        return;
    } else if(s.length() == 1){
        char ch = s[0];
        if(ch == '0'){
            return;
        } else {
            int chl = ch - '0';
            char code = (char)('a' + chl - 1);
            cout<<coding + code<<endl;
        }
    } else {
        char ch = s[0];
        if(ch == '0'){
            return;
        } else {
            int chl = ch - '0';
            char code = (char)('a' + chl - 1);
            printEncodings(s.substr(1) , coding + code);
        }

         string ch12 = s.substr(0,2);
            
         int ch12v = stoi(ch12);
         if(ch12v <= 26){
             char code = (char)('a' + ch12v - 1);
             printEncodings(s.substr(2) , coding + code);
         }   
    }      
}
int main(){
    string s; cin>>s;
    printEncodings(s , "");
    return 0;
}