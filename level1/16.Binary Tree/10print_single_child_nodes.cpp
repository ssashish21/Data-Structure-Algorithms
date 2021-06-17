#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data){
		this->data = data;
		left = nullptr;
		right = nullptr;
	}

	~TreeNode(){
		delete left;
		delete right;
	}
};

TreeNode* takeInput(){
	string rootData;
	cin >> rootData;

	if(rootData == "n"){
		return nullptr;
	}

	TreeNode* root = new TreeNode(stoi(rootData));
	TreeNode* leftchild = takeInput();
	TreeNode* rightchild = takeInput();

	root->left = leftchild;
	root->right = rightchild;
	return root;
}

void printSingleChildNode(TreeNode* root){
	if(root == nullptr){
		return;
	}

	if(root->left && !root->right){
		cout << root->left->data << endl;
	}
	
	if(!root->left && root->right){
		cout << root->right->data << endl;
	}

	printSingleChildNode(root->left);
	printSingleChildNode(root->right);
}

int main(){
	int n;
	cin >> n;
	TreeNode * root = takeInput();
	printSingleChildNode(root);
}