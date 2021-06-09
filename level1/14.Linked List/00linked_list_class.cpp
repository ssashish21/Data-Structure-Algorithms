#include<iostream>
using namespace std;

class Node{
public:
	int val;
	Node* next;

public:
	Node(){
		val = 0;
		next = nullptr;
	}

	Node(int val){
		this->val = val;
		next = nullptr;
	}

	Node(int val, Node * next){
		this->val = val;
		this->next = next;
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
};