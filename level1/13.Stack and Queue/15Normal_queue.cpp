#include<iostream>
using namespace std;

template<typename T>
class queue{
    T* data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    queue(int siz){
        data = new T[siz];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = siz;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void display(){
        int s = size;
        for(int i = firstIndex ; i < capacity ; i++){
            if(s-- > 0)
            cout<<data[i]<<" ";
        } 
        for(int i = 0 ; i < firstIndex ; i++){
            if(s-- > 0)
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    void enqueue(int val){
        if(size == capacity){
            cout<<"Queue overflow"<<endl;
            return;
        }
        data[nextIndex] = val;
        nextIndex = (nextIndex + 1) % capacity;
        if(firstIndex == -1){
            firstIndex = 0;
        }
        size++;
    }

    T front(){
        if(isEmpty()){
            cout<<"Queue underflow"<<endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue(){
        if(isEmpty()){
            cout<<"Queue underflow"<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        return ans;
    }
};

int main(){
    int size; cin>>size;
    string query;
    queue<int> q(size);
    while(1){
        cin>>query;
        if(query == "quit"){
            break; 
        } else if(query == "add"){
            int val; cin>>val;
            q.enqueue(val);
        } else if(query == "display"){
            q.display();
        } else if(query == "peek"){
            int val = q.front();
            if(val != 0) cout<<val<<endl;
        } else if(query == "remove"){
            int val = q.dequeue();
            if(val != 0) cout<<val<<endl;
        } else if(query == "size"){
            cout<<q.getSize()<<endl;
        }
    }
}