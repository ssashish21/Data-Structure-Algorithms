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

int max(BSTNode* root){
	if(root->right){
		return max(root->right);
	} else{
		return root->data;
	}
}

BSTNode* removeNode(BSTNode* root , int val){
	if(!root) return nullptr;

	if(val > root->data){
		root->right = removeNode(root->right , val);
	} else if(val < root->data){
		root->left = removeNode(root->left , val);
	} else {
		//work place
		if(root->left!=nullptr && root->right!=nullptr){
			int lmax = max(root->left);
			root->data = lmax;
			root->left = removeNode(root->left , lmax);
		} else if(root->left!=nullptr){
			return root->left;
		} else if(root->right!=nullptr){	
			return root->right;
		} else {
			return nullptr;
		}
	}
	return root;
}


int main(){
	int n;
	cin >> n;

	BSTNode* root = takeInput();
	int val;
	cin >> val;

	removeNode(root , val);
	display(root);
}