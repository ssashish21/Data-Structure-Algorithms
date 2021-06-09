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

	void display(){
		if(isEmpty()){
			cout << "0";
			return;
		}

		Node* temp = head;
		while(temp != nullptr){
			cout << temp->data << endl;
			temp = temp -> next;
		}
		cout << size << endl;
		cout << tail->data << endl;
	}

	void display1(){
		Node* temp = head;
		while(temp != nullptr){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
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
	

	int removeFirst(){
		int val;
		if(isEmpty()){
			cout << "Queue underflow" << endl;
			return -1;
		} else if(size == 1){
			val = head->data;
			head = nullptr;
			tail = nullptr;
		} else {
			val = head->data;
			head = head->next;
		}
		size = size - 1;
		return val;
 	}

 	

 	int getFirst(){
 		if(head == nullptr){
 			cout << "Queue underflow" << endl;
 			return -1;
 		}
 		return head->data;
 	} 

};

int main(){
	LinkedList l;
	string q;
	while(1){
		cin >> q;
		if(q == "quit"){
			break;
		} else if(q == "add"){
			int val;
			cin >> val;
			l.addLast(val);
		} else if(q == "remove"){
			int val = l.removeFirst();
			if(val != -1)
				cout << val << endl;
		} else if(q == "peek"){
			int val = l.getFirst();
			if(val != -1)
				cout << val << endl;
		} else if(q == "size"){
			l.size1();
		}
	}
}