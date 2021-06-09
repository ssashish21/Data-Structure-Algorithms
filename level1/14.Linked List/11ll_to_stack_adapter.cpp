#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int val){
		data = val;
		next = nullptr;
	}
};

class LinkedList{
public:
	Node* head;
	Node* tail;
    int size;

	LinkedList(){
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	bool isEmpty(){
		return head == nullptr;
	}	


	void size1(){
		cout << this->size << endl;
	}

	void addLast(int val){
		Node* newNode = new Node(val);
		if(isEmpty()){
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = tail->next;
		}
		size = size + 1;
	}


 	int removeLast(){
 		if(isEmpty()){
 			cout << "List is empty" << endl;
 			return -1;
 		} else if(size == 1){
 			int val = tail->data;
 			head = nullptr;
 			tail = nullptr;
 			return val;
 		} 
 		int val = tail->data;
 		Node* temp = head;
 		for(int i = 1 ; i < size - 1 ; i++)
 			temp = temp -> next;

 		tail = temp;
 		temp -> next = nullptr;
 		size = size - 1;

 		return val;
 	}

 	int getLast(){
 		if(tail == nullptr){
 			cout << "List is empty" << endl;
 			return -1;
 		}
 		return tail->data;
 	} 	
};

int main(){
	LinkedList l;
	string q;
	int val;
	while(1){
		cin >> q;
		if(q == "quit"){
			break;
		} else if(q == "push"){
			cin >> val;
			l.addLast(val);
		} else if(q == "pop"){
			int val = l.removeLast();
			if(val!= -1) 
				cout << val << endl;
		} else if(q == "top"){
			int val = l.getLast();
			if(val != -1)
				cout << val << endl;
		} else if(q == "size"){
			l.size1();
		}
	}
}