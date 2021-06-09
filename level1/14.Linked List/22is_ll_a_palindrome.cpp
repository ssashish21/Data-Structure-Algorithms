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
    
    bool isPalindrome(Node* right){
        if(right == NULL) return true;
        
        bool rr = isPalindrome(right->next);
        
        if(rr == false || left->data != right->data){
            return false;
        }  else {
            left = left->next;
            return true;
        }
    }
    
    Node* left;
    bool isPalindrome(){
        left = head;
        return isPalindrome(head);
    }
};

int main(){
    int val;
    int n; cin >> n; LinkedList l;
    for(int i = 0 ; i < n ; i++){
        cin>>val;
        l.addLast(val);
    }
    bool isP =  l.isPalindrome();
    
    string ans = isP == true ? "true" : "false";
    cout<<ans;  
}