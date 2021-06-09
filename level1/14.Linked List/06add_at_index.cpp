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

	void addFirst(int val){
		Node* newNode = new Node(val);
		if(isEmpty()){
			head = newNode;
			tail = newNode;
		} else {
			newNode->next = head;
			head = newNode;
		}
		size = size + 1;
	}

	void addAt(int pos , int val){
		if(pos < 0 || pos > size){
			cout << "Invalid arguments" << endl;
			return;
		} else if(pos == 0){
			addFirst(val);
			return;
		} else if(pos == size){
			addLast(val);
			return;
		}

		Node* newNode = new Node(val);
		Node* temp = head;

		for(int i = 0 ; i < pos - 1 ; i++){
			temp = temp -> next;
		}

		newNode -> next = temp -> next;
		temp -> next = newNode;
		size = size + 1;
	}

	void removeFirst(){
		if(isEmpty()){
			cout << "List is empty" << endl;
			return;
		} else if(size == 1){
			head = nullptr;
			tail = nullptr;
		} else {
			head = head->next;
		}
		size = size - 1;
 	}

 	int getFirst(){
 		if(head == nullptr){
 			cout << "List is empty" << endl;
 			return -1;
 		}
 		return head->data;
 	} 

 	int getLast(){
 		if(tail == nullptr){
 			cout << "List is empty" << endl;
 			return -1;
 		}
 		return tail->data;
 	} 

	int getAt(int pos){
		if(isEmpty()){
			cout << "List is empty" << endl;
			return -1;
		} else if(pos < 0 || pos >= size){
			cout << "Invalid arguments" << endl;
			return -1;
		} 

		Node* temp = head;
		for(int i = 0 ; i < pos && temp != nullptr ; i++){
			temp = temp -> next;
		}
		return temp->data;
 	}

};

int main(){
	LinkedList l;
	string q;
	while(1){
		cin >> q;
		if(q == "quit"){
			break;
		} else if(q == "addLast"){
			int val;
			cin >> val;
			l.addLast(val);
		} else if(q == "display"){
			l.display1();
		} else if(q == "size"){
			l.size1();
		} else if(q == "removeFirst"){
			l.removeFirst();
		} else if(q == "getFirst"){
			int val = l.getFirst();
			if(val != -1)
				cout << val << endl;

		} else if(q == "getLast"){
			int val = l.getLast();
			if(val != -1)
				cout << val << endl;

		} else if(q == "getAt") {
			int pos;
			cin >> pos;
			int val = l.getAt(pos);
			if(val != -1)
				cout << val << endl;
		} else if(q == "addFirst"){
			int val;
			cin >> val;

			l.addFirst(val);
		} else if(q == "addAt"){
			int pos , val;
			cin >> pos >> val;

			l.addAt(pos , val);
		}
	}
}