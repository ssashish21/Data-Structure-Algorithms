#include<iostream>
#include<stack>
using namespace std;
class myQueuePush{
    stack<int> mainS;
    stack<int> helperS;

    public:
    int size(){
        return mainS.size();
    }

    void push(int val){    
        mainS.push(val);
    }

    int pop(){
        if(mainS.size() == 0){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        while(mainS.size() > 1){
            helperS.push(mainS.top());
            mainS.pop();
        }
        int val = mainS.top();
        mainS.pop();

        while(helperS.size() > 0){
            mainS.push(helperS.top());
            helperS.pop();
        }
        return val;
    }

    int front(){
        if(mainS.size() == 0){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        while(mainS.size() > 1){
            helperS.push(mainS.top());
            mainS.pop();
        }
        int val = mainS.top();
        mainS.pop();
        helperS.push(val);

        while(helperS.size() > 0){
            mainS.push(helperS.top());
            helperS.pop();
        }
        return val;
    }
};

int main(){
    string qry;
    myQueuePush q;
    while(1){
        cin>>qry;
        if(qry == "quit"){
            break;
        } else if(qry == "add"){
            int val; cin>>val;
            q.push(val); 
        } else if(qry == "remove"){
            int val = q.pop();
            if(val != -1) cout<<val<<endl;
        } else if(qry == "peek"){
            int val = q.front();
            if(val != -1) cout<<val<<endl;
        } else if(qry == "size"){
            cout<<q.size()<<endl;
        }
    }
}