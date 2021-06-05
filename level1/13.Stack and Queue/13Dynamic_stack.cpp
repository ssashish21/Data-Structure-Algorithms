#include<iostream>
using namespace std;
class stack{
    int* data;
    int  capacity;
    int  cp;

    public:
        
    stack(int capacity){
        data = new int[capacity];
        this->capacity = capacity;
        cp = -1;
    }

    int size(){
        return cp + 1;
    }

    void display(){
        for(int i = cp ; i >= 0; i--){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    void push(int value){
        if(cp == capacity - 1){
            capacity *= 2;
            int* newData = new int[capacity];
            for(int i = 0 ; i <= cp ; i++){
                newData[i] = data[i];
            }
            int* temp = data;
            data = newData;
            cp++;
            data[cp] = value;
            delete[]temp;
        } else {
            cp++;
            data[cp] = value;
        }
    }

    int pop(){
        if(cp == -1){
            cout<<"Stack underflow"<<endl;
            return -1;
        } else {
            int val = data[cp];
            cp--;
            return val;
        }
    }

    int top(){  
        if(cp == -1){
            cout<<"Stack underflow"<<endl;
            return -1;
        } else {
            return data[cp];
        }
    }

};

int main(){
    int size; cin>>size;
    stack s(size);
    string query;
    while(1){
        cin>>query;
        if(query == "quit"){
            break;
        } else if(query == "push"){
            int val;
            cin>>val;
            s.push(val);
        } else if(query == "display"){
            s.display();
        } else if(query == "pop"){
            int val = s.pop();
            if(val != -1) cout<<val<<endl;
        } else if(query == "top"){
            int val = s.top();
            if(val != -1) cout<<val<<endl;
        } else if(query == "size"){
            cout<<s.size()<<endl;
        }
    }
}