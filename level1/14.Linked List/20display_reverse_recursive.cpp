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
    
    
    void displayReverse(Node* head){
        if(head == NULL){
            return;
        }    
        
        displayReverse(head->next);
        cout<<head->data<<" ";
    }
    
    void displayReverse(){
        displayReverse(head);
        cout<<endl;
    }
};


int main(){
    int val;
    int n; cin >> n; LinkedList l;
    for(int i = 0 ; i < n ; i++){
        cin>>val;
        l.addLast(val);
    }
    int a , b; cin >> a >> b;
    l.display();
    l.displayReverse();
    l.addFirst(b);
    l.addLast(a);
    l.display();
}