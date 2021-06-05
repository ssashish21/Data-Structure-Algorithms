#include<iostream>
using namespace std;
class stack{
    int *data;
    int capacity;
    int curr;
    public:

    stack(int cap){
        data = new int[cap];
        capacity = cap;
        curr = -1;
    }

    int size(){
        return curr + 1;
    }

    void display(){
        for(int i = curr ; i >= 0 ; i--){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    void push(int val){
        if(curr == capacity - 1){
             cout<<"Stack overflow"<<endl;
             return;
        }
        else{
            curr++;
            data[curr]=val;
        }
    }

    int pop(){
        if(curr==-1) {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        else{
            int val= data[curr];
            curr--;
            return val;
        }   
    }

    int top(){
        if(curr==-1) {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        else{
            return data[curr];
        }
    }
};

int main(){
    int lol;
    cin>>lol;
    stack s(lol);
    string query;
    while(1){
        cin>>query;
             if(query=="quit")
             break;
            else if(query=="push"){
            int val;
            cin>>val;
            s.push(val);
            }
            else if(query=="pop"){
                int val = s.pop();
                if(val != -1)
                    cout<<val<<endl;
            } 
            else if(query=="top"){
                int  val = s.top();
                if(val != -1)
                    cout<<val<<endl;
            }
            else if(query=="display"){
                s.display();
            }
            else if(query=="size"){ 
                cout<<s.size()<<endl;
            }
      }   
}