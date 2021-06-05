#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
class stack1{
    public:
    stack<int> alldata;
    stack<int> mindata;
    
   
    int size(){
        return alldata.size();
    }
   
    void push(int val){
        alldata.push(val);
        if(mindata.size()==0 || val <= mindata.top())
            mindata.push(val);
    }

    int pop(){
        if(alldata.size()==0) {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        else {
            int val=alldata.top(); alldata.pop();
            if(val==mindata.top()){
                mindata.pop();
            }
            return val;
        }
        
    }
    int top(){
        if(alldata.size()==0) {
            cout<<"Stack underflow"<<endl;
            return -1;
        }else {
            return alldata.top();
        }
    }
    int min(){
        if(mindata.size()==0) {
            cout<<"Stack underflow"<<endl;
            return -1;
        }else {
            return mindata.top();
        }
    }
};
int main(){
    stack1 s;
    string query;
    cin>>query;
    while(1){
        if(query=="quit"){
           break;
        }
        else if(query=="push"){
            int val;
            cin>>val;
            s.push(val);
        }
        else if(query=="pop"){
            int  data=s.pop();
            if(data!=-1)
            cout<<data<<endl;
        } 
        else if(query=="top"){
            int  data=s.top();
            if(data!=-1)
            cout<<data<<endl;
        }
        else if(query=="size"){
            int size=s.size();
            cout<<size<<endl;
        }
        else if(query=="min"){
            int data=s.min();
            if(data!=-1)
            cout<<data<<endl;
        }
        cin>>query;
      }
}