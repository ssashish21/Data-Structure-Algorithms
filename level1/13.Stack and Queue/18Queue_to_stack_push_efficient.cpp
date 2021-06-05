#include<iostream>
#include<queue>
using namespace std;
class myStackPush{
    queue<int> mainQ;
    queue<int> helperQ;

    public:
    int size(){
        return mainQ.size();
    }

    void push(int val){    
        mainQ.push(val);
    }

    int pop(){
        if(mainQ.size() == 0){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        while(mainQ.size() > 1){
            helperQ.push(mainQ.front());
            mainQ.pop();
        }

        int val = mainQ.front();
        mainQ.pop();

        while(helperQ.size() > 0){
            mainQ.push(helperQ.front());
            helperQ.pop();
        }
        return val;
    }

    int top(){
        if(mainQ.size() == 0){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        while(mainQ.size() > 1){
            helperQ.push(mainQ.front());
            mainQ.pop();
        }

        int val = mainQ.front();
        mainQ.pop();
        helperQ.push(val);

        while(helperQ.size() > 0){
            mainQ.push(helperQ.front());
            helperQ.pop();
        }
        return val;
    };
};
int main(){
    string qry;
    myStackPush st;
    while(1){
        cin>>qry;
        if(qry == "quit"){
            break;
        } else if(qry == "push"){
            int val; cin>>val;
            st.push(val); 
        } else if(qry == "pop"){
            int val = st.pop();
            if(val != -1) cout<<val<<endl;
        } else if(qry == "top"){
            int val = st.top();
            if(val != -1) cout<<val<<endl;
        } else if(qry == "size"){
            cout<<st.size()<<endl;
        }
    }
}