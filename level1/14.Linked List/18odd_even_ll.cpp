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
    
    void oddEven(){
        LinkedList odd;
        LinkedList even;
        
        while(size1() > 0){
            int val = getFirst();
            removeFirst();
            
            if(val&1) odd.addLast(val);
            else even.addLast(val);
        }
        
        if(odd.size > 0 && even.size > 0){
            odd.tail->next = even.head;
            head = odd.head;
            tail = even.tail;
            size = odd.size + even.size;
        } else if(odd.size1() > 0){
            head = odd.head;
            tail = odd.tail;
            size = odd.size;
        } else {
            head = even.head;
            tail = even.tail;
            size = even.size;
        }
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
    l.oddEven();
    l.display();
    l.addFirst(a);
    l.addLast(b);
    l.display();
}