#include<iostream>
#include<stack>
using namespace std;

bool isBalance(string str){
    stack<char> st;
    for(auto ch : str){
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        } else if(ch == ')'){
            if(!st.empty() && st.top() == '(')
                st.pop();
            else 
                return false;
        } else if(ch == '}'){
            if(!st.empty() && st.top() == '{')
                st.pop();
            else 
                return false;
        } else if(ch == ']'){
            if(!st.empty() && st.top() == '[')
                st.pop();
            else 
                return false;
        }
    }

    return st.empty();
}

int main(){
    string str;
    getline(cin , str);
    
    bool ok = isBalance(str);
    if(ok)
        cout <<"true";
    else
        cout <<"false";
}