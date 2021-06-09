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
    
    
    void fold(Node* right , int floor){
        if(right == NULL) return;
        
        fold(right->next , floor + 1);
        
        if(floor > size / 2){
            Node* temp = fleft->next;
            fleft->next = right;
            right->next = temp;
            fleft = temp;
        } else if(floor == size/2){
            tail = right;
            tail->next = NULL;
        }
    }
    
    Node* fleft;
    void fold(){
        fleft = head;
        fold(head , 0);
    }
};

int main(){
    int val;
    int n;
    cin >> n;
    LinkedList l;
    for(int i = 0 ; i < n ; i++){
        cin>>val;
        l.addLast(val);
    }

    int a , b;
    cin >> a >> b;

    l.display();
    l.fold();
    l.display();
    l.addFirst(a);
    l.addLast(b);
    l.display();
}