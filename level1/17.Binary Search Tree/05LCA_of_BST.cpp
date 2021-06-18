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

int LCA(BSTNode* root , int val1 , int val2){
	if(root->data < val1 && root->data < val2){
		return LCA(root->right , val1 , val2);
	} else if(root->data > val1 && root->data > val2){
		return LCA(root->left , val1 , val2);
	} else {
		return root->data;
	}
}

int main(){
	int n;
	cin >> n;

	BSTNode* root = takeInput();
	
	int val1 , val2;
	cin >> val1 >> val2;

	int lca = LCA(root , val1 , val2);
	cout << lca;
}