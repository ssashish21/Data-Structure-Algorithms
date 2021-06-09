#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node * next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

class LinkedList {
    public:
        Node* head;
        Node* tail;
        int size;
        
        LinkedList(){
            this->head = NULL;
            this->tail = NULL;
            this->size = 0;
        }
    
    bool isEmpty(){
        return head == NULL;
    }
    
        
    void addLast(int val){
        Node* newNode = new Node(val);
        if(isEmpty()){
            head = newNode;
            tail = newNode;
        } else {
            tail = tail->next = newNode;
        }
        size = size + 1;
    }
    
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data << " ";
            temp = temp -> next;
        }
        cout<<endl;
    }
    
    int size1(){
        return this->size;
    }
    
    void removeFirst(){
        if(isEmpty()){                  // case 1 : list is empty
            cout<<"List is empty"<<endl;
            return;
        } else if(size == 1){           // case 2 : list contain one element
            head = NULL;
            tail = NULL;
        } else {                        // case 3 : general case
            head = head->next;
        }
        size--;
    }
    
    int getFirst(){
        if(isEmpty()){
            cout<<"List is empty"<<endl;
            return -1;
        }
        return head -> data;
    }
    
    
    void removeDuplicates(){
        LinkedList res;
        
        while(size1() > 0){
            int val = getFirst();
            removeFirst();
            
            if(res.size1() == 0 || val != res.tail->data){
                res.addLast(val);
            }
        }
        head = res.head;
        tail = res.tail;
        size = res.size;
    }
};


int main(){
    int val;
    int n; cin >> n; LinkedList l;
    for(int i = 0 ; i < n ; i++){
        cin>>val;
        l.addLast(val);
    }
    
    l.display();
    l.removeDuplicates();
    l.display();
}