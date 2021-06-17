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

bool isBST(TreeNode* root , int mn , int mx){
	if(!root) return true;

	if(root->data < mn || root->data > mx) return false;

	bool l = isBST(root->left , mn , root->data - 1);
	bool r = isBST(root->right , root->data + 1 , mx);

	return l && r;
}

string isBST(TreeNode* root){
	bool res = isBST(root , INT_MIN , INT_MAX);
	return res ? "true" : "false";
}

int main(){
	int n;
	cin >> n;
	TreeNode * root = takeInput();
	cout << isBST(root);
}