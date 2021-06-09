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
    

    Node* getNodeAt(int idx) {
      Node* temp = this->head;
      for (int i = 0; i < idx; i++) {
        temp = temp->next;
      }
      return temp;
    }
};


int findIntersection(LinkedList one , LinkedList two){
    Node* t1 = one.head;
    Node* t2 = two.head;
    
    int delta = abs(one.size - two.size);
    
    if(one.size > two.size)
        for(int i = 0 ; i < delta ; i++)
            t1 = t1->next;
    
    if(one.size < two.size)
        for(int i = 0 ; i < delta ; i++)
            t2 = t2->next;
            
    while(t1 != t2){
        t1 = t1->next;
        t2 = t2->next;
    }
    return t1->data;
}

int main(){
    int n1 , n2;
    LinkedList l1;
    cin>>n1;
    for(int i = 0 ; i < n1 ; i++){
        int data; cin>>data;
        l1.addLast(data);
    }
    cin>>n2;
    LinkedList l2;
    for(int i = 0 ; i < n2 ; i++){
        int data; cin>>data;
        l2.addLast(data);
    }

    int li , di;
    cin>>li>>di;

    if(li == 1){
        Node* n = l1.getNodeAt(di);
        l2.tail->next = n;
        l2.tail = l1.tail;
        l2.size += l1.size - di;
    } else {
        Node* n = l2.getNodeAt(di);
        l1.tail->next = n;
        l1.tail = l2.tail;
        l1.size += l2.size - di;
    }
    
    int inner = findIntersection(l1 , l2);
    cout<<inner<<endl;
}