#include<bits/stdc++.h>
using namespace std;

class BSTNode{
public:
	int data;
	BSTNode* left;
	BSTNode* right;

	BSTNode(){
		data = 0;
		left = nullptr;
		right = nullptr;
	}

	BSTNode(int data){
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}

	~BSTNode(){
		delete left;
		delete right;
	}
};

BSTNode* takeInput(){
	string rootData;
	cin >> rootData;

	if(rootData == "n"){
		return nullptr;
	}

	BSTNode* root = new BSTNode(stoi(rootData));

	root->left = takeInput();
	root->right = takeInput();

	return root;
}


BSTNode* addNodeToBST(BSTNode* root , int val){
	if(root == nullptr){
		BSTNode* nn = new BSTNode(val);
		return nn;
	}
	if(val > root->data){
		root->right = addNodeToBST(root->right , val);
	} else if(val < root->data){
		root->left = addNodeToBST(root->left , val);
	} else {

	}
	return root;
}


void display(BSTNode* root){
	if(!root){
		return;
	}

	if(root->left){
		cout << root->left->data;
	} else {
		cout << ".";
	}
	cout <<" <- " << root->data << " -> ";
	if(root->right){
		cout << root->right->data;
	} else {
		cout << ".";
	}
	cout << endl;

	display(root->left);
	display(root->right);
}



int main(){
	int n;
	cin >> n;

	BSTNode* root = takeInput();
	int val;
	cin >> val;

	addNodeToBST(root , val);
	display(root);
}