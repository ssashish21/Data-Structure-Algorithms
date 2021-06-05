#include<iostream>
#include<stack>
using namespace std;
class myQueuePop{
    stack<int> mainS;
    stack<int> helperS;

    public:
    int size(){
        return mainS.size();
    }

    void push(int val){    
        while(mainS.size() > 0){
            helperS.push(mainS.top());
            mainS.pop();
        }

        mainS.push(val);

        while(helperS.size() > 0){
            mainS.push(helperS.top());
            helperS.pop();
        }
    }

    int pop(){
        if(mainS.size() == 0){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
       int val = mainS.top();
       mainS.pop();
       return val;
    }

    int front(){
        if(mainS.size() == 0){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        return mainS.top();
    }
};

int main(){
    string qry;
    myQueuePop q;
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