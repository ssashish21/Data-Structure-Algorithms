#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str;
    getline(cin , str);
    
    stack<char> st;
    for(auto ch : str){
        if(ch == ' ') continue;
        
        if(ch == ')'){
            if(st.top() == '('){
                cout << "true";
                return 0;
            } else {
                while(st.top() != '(')
                    st.pop();
                st.pop();
            }
        } else {
            st.push(ch);
        }
    }
    cout <<"false";
}