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

int height(TreeNode* root){
	if(!root) return 0;

	int lh = height(root->left);
	int rh = height(root->right);

	if(lh == -1 || rh == -1 || abs(lh - rh) > 1)
		return -1;

	return max(lh , rh) + 1;
}

string isBalancedTree(TreeNode* root){
	if(height(root) == -1){
		return  "false";
	} else {
		return "true";
	}
}

int main(){
	int n;
	cin >> n;
	TreeNode * root = takeInput();
	cout << isBalancedTree(root);
}