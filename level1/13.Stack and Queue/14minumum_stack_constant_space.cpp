#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
class Stack{
    stack<int> s;
    int min;
    public:

    Stack(){
        // s = new stack<int>();
    }   

    int size(){
        return s.size();
    }


    void push(int val){
       if(s.size() == 0){
            s.push(val);
            min = val;
       } else if(val >= min) {
            s.push(val);
       } else {
            s.push(val + val - min);
            min = val;
       }
    }

    int pop(){
        if(size() == 0){
            cout <<"Stack Underflow" << endl;
            return -1;
        } else {
            int val = s.top();
            s.pop();

            if(val >= min){
                int v2r = val;
                return v2r;
            } else {
                int v2r = min;
                min = (2 * min) - val;
                return v2r;
            }
        }
    }

    int top(){
        if(size() == 0){
            cout <<"Stack Underflow" << endl;
            return -1;
        } else {
            int t = s.top();
            if(t >= min){
                return t;
            } else {
                return min;
            }
        }
    }

    int minVal(){
        if(size() == 0){
            cout <<"Stack Underflow" << endl;
            return -1;
        } else {
            return min;
        }
    }
};

int main(){
    Stack st;
    string query;
    while(1){
        cin>>query;
        if(query=="quit"){
          break;
        } else if(query=="push"){
            int val;
            cin>>val;
            st.push(val);
        } else if(query=="pop"){
            int val = st.pop();
            if(val != -1)
                cout<<val<<endl;
        } else if(query=="top"){
            int  val = st.top();
            if(val != -1)
                cout<<val<<endl;
        } else if(query=="size"){ 
            cout<<st.size()<<endl;
        } else if(query == "min"){
            int val = st.minVal();
            if(val != 0)
                cout <<val<< endl;
        }
  }   
}


