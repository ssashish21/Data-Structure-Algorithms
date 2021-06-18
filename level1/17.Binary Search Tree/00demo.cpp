#include<bits/stdc++.h>
using namespace std;

class BstNode{
public:
	int data;
	BstNode* left;
	BstNode* right;

	BstNode(){
		data = 0;
		left = nullptr;
		right = nullptr;
	}

	BstNode(int data){
		this->data = data;
		left = nullptr;
		right = nullptr;
	}

};

void display(BstNode* root){
	if(!root) return;

	cout << root->data << " ";

	display(root->left);
	display(root->right);
}

int main(){
	BstNode* root = new BstNode(10);
	root->left = new BstNode(20);
	root->right = new BstNode(20);

	display(root);	
}