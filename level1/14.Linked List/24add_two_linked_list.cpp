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
};

int addTwoList(Node* one , int pv1 , Node* two , int pv2 , LinkedList &res){
    if(one == NULL && two == NULL){
        return 0;
    }
    
    int data = 0;
    if(pv1 > pv2){
        int oc = addTwoList(one->next , pv1 - 1 , two , pv2 , res);
        data = one->data + oc;
    } else if(pv1 < pv2){
        int oc = addTwoList(one , pv1 , two->next , pv2 - 1 , res);
        data = two->data + oc;
    } else {
        int oc = addTwoList(one->next , pv1 - 1 , two->next , pv2 - 1, res);
        data = one->data + two->data + oc;
    }
    
    int nd = data % 10;
    int nc = data / 10;
    
    res.addFirst(nd);
    return nc;
    
}

LinkedList addTwoList(LinkedList one , LinkedList two){
    LinkedList res;
    
    int oc = addTwoList(one.head , one.size , two.head , two.size , res);
    
    if(oc > 0){
        res.addFirst(oc);
    }
    
    return res;
}

int main(){
    int val;
    int n; cin >> n; LinkedList l;
    for(int i = 0 ; i < n ; i++){
        cin>>val;
        l.addLast(val);
    }
    int n1; cin >> n1; LinkedList l1;
    for(int i = 0 ; i < n1 ; i++){
        cin>>val;
        l1.addLast(val);
    }
    
    int a , b;
    cin >> a >> b;
    
    LinkedList sum = addTwoList(l , l1);

    l.display();
    l1.display();
    sum.display();
    sum.addFirst(a);
    sum.addLast(b);
    sum.display();
    
}