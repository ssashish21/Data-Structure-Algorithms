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

Node* midNode(Node* head , Node* tail){
    Node* s = head;
    Node* f = head;
    
    while(f!=tail && f->next!=tail){
        s = s -> next;
        f = f -> next -> next;
    }
    return s;
}

LinkedList mergeSort(Node* head , Node* tail){
    if(head == tail){
        LinkedList br;
        br.addLast(head->data);
        return br;
    }
    
    Node* mid = midNode(head , tail);
    LinkedList fsh = mergeSort(head , mid);
    LinkedList ssh = mergeSort(mid->next , tail);
    LinkedList sl = mergeTwoSortedList(fsh , ssh);
    return sl;
    
}

int main(){
    int val;
    int n; cin >> n; LinkedList l;
    for(int i = 0 ; i < n ; i++){
        cin>>val;
        l.addLast(val);
    }
    
    LinkedList sl = mergeSort(l.head , l.tail);
    sl.display();
    l.display();
}