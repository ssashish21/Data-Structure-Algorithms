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
 
    
    void addFirst(int val){
        Node* nn = new Node(val);
        if(isEmpty()){
            head = tail = nn;
        } else {
            nn->next = head;
            head  = nn;
        }
        size++;
    }    
    
    void kreverse(int k){
        LinkedList res;
        
        while(size > 0){
            LinkedList curr;
            
            if(size >= k){
                for(int i = 0 ; i < k ; i++){
                    int val = getFirst();
                    removeFirst();
                    curr.addFirst(val);
                }
            } else {
                int os = size;
                for(int i = 0 ; i < os ; i++){
                    int val = getFirst();
                    removeFirst();
                    curr.addLast(val);
                }
            }
            
            if(res.head == NULL){
                res = curr;
            } else {
                res.tail->next = curr.head;
                res.tail = curr.tail;
                res.size += curr.size;
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
    int k ; cin >> k;
    int a , b; cin >> a >> b;
    l.display();
    l.kreverse(k);
    l.display();
    l.addFirst(a);
    l.addLast(b);
    l.display();
}