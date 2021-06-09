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
};

LinkedList mergeTwoSortedList(LinkedList l1 , LinkedList l2){
    LinkedList res;
    Node* i = l1.head;
    Node* j = l2.head;
    while(i != NULL && j != NULL){
        if(i->data < j->data){
            res.addLast(i->data);
            i = i -> next;
        } else {
            res.addLast(j->data);
            j = j->next;
        }
    }
    while(i!=NULL){
        res.addLast(i->data);
        i = i -> next;
    }
    while(j!=NULL){
        res.addLast(j->data);
        j = j -> next;
    }
    
    return res;
}

int main(){
    int val , n1;
    cin >> n1;
    LinkedList l1;
    for(int i = 0 ; i < n1 ; i++){
        cin>>val;
        l1.addLast(val);
    }
    
    int n2;
    cin >> n2; 
    LinkedList l2;
    for(int i = 0 ; i < n2 ; i++){
        cin>>val;
        l2.addLast(val);
    }
    
    LinkedList l = mergeTwoSortedList(l1 , l2);
    
    l.display();
    l1.display();
    l2.display();   
}