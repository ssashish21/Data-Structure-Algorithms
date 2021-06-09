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

 	void removeLast(){
 		if(isEmpty()){
 			cout << "List is empty" << endl;
 			return;
 		} else if(size == 1){
 			head = nullptr;
 			tail = nullptr;
 		} 
 		Node* temp = head;
 		for(int i = 1 ; i < size - 1 ; i++)
 			temp = temp -> next;

 		tail = temp;
 		temp -> next = nullptr;
 		size = size - 1;
 	}

 	void removeAt(int pos){
 		if(pos < 0 || pos >= size){
 			cout << "Invalid arguments" << endl;
 			return;
 		} else if(pos == 0){
 			removeFirst();
 		} else if(pos == size - 1){
 			removeLast();
 		} else {
 			Node * temp = head;
 			for(int i = 1 ; i <= pos - 1 ; i++)
 				temp = temp->next;

 			temp->next = temp->next->next;
 			size = size - 1;
 		}
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

 private:
 	Node* getNodeAt(int pos){
 		Node* temp = head;
		for(int i = 0 ; i < pos && temp != nullptr ; i++){
			temp = temp -> next;
		}
		return temp;
 	}

 public:
 	void reverseDI(){
 		int li = 0;
 		int ri = size - 1;

 		while(li < ri){
 			Node* left = getNodeAt(li);
 			Node* right = getNodeAt(ri);

 			int temp = left->data;
 			left->data = right->data;
 			right->data = temp;

 			li++;
 			ri--;
 		}
 	}

 	void reversePI(){
 		Node* p = head;
 		Node* q = nullptr;
 		Node* r = nullptr;

 		while(p != nullptr){
 			r = q;
 			q = p;
 			p = p->next;
 			q->next = r;
 		}

 		tail = head;
 		head = q;
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
		} else if(q == "removeLast"){
			l.removeLast();
		} else if(q == "removeAt"){
			int pos;
			cin >> pos;

			l.removeAt(pos);
		} else if(q == "reverseDI"){
			l.reverseDI();
		} else if(q == "reversePI"){
			l.reversePI();
		}
	}
}