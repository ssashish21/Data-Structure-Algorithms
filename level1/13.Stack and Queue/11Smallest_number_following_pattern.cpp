#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s;
    cin>>s;

    stack<int> st;

    int num = 1;
    for(int i = 0 ; i < s.size() ; i++){
        char ch = s[i];
        if(ch == 'd'){
            st.push(num++);
        } else {
            st.push(num++);
            while(st.size() > 0){
                cout<<st.top();
                st.pop();
            }
        }
    }
    
    st.push(num);
    while(st.size() > 0){
        cout<<st.top();
        st.pop();
    }
}