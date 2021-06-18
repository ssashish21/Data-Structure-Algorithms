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

void printInRange(BSTNode* root , int l , int r){
	if(!root) return;

	if(l > root->data && r > root->data){
		printInRange(root->right , l , r);
	} else if(l < root->data && r < root->data){
		printInRange(root->left , l , r);
	} else {
		printInRange(root->left , l , r);
		cout << root->data << endl;
		printInRange(root->right , l , r);
	}
}

int main(){
	int n;
	cin >> n;

	BSTNode* root = takeInput();
	
	int val1 , val2;
	cin >> val1 >> val2;

	printInRange(root, val1 , val2);
}