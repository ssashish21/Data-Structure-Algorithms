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

int size(TreeNode * root){
	if(!root) return 0;

	int l = size(root->left);
	int r = size(root->right);
	return 1 + l + r;
}

int sum(TreeNode* root){
	if(!root) return 0;

	int lsum = sum(root->left);
	int rsum = sum(root->right);
	return root->data + lsum + rsum;
}

int max(TreeNode* root){
	if(!root){
		return INT_MIN;
	}
	int lmax = max(root->left);
	int rmax = max(root->right);
	return max({root->data , lmax , rmax});
}

int height(TreeNode* root){
	if(!root){
		return -1;
	}

	int lheight = height(root->left);
	int rheight = height(root->right);
	return max(lheight , rheight) + 1;
}


int main(){
	int n;
	cin >> n;
	TreeNode * root = takeInput();
	
	cout << size(root) << endl;
	cout << sum(root) << endl;
	cout << max(root) << endl;
	cout << height(root) << endl;
}