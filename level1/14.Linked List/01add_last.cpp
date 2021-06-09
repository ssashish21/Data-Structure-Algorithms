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
};

int main(){
	LinkedList l;
	string q;
	while(1){
		cin >> q;
		if(q == "quit"){
			l.display();
			break;
		} else if(q == "addLast"){
			int val;
			cin >> val;
			l.addLast(val);
		}
	}
}