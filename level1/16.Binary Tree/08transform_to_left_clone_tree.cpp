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

TreeNode* createLeftCloneTree(TreeNode* root){
	if(root == nullptr){
		return nullptr;
	}

	TreeNode* lcc = createLeftCloneTree(root->left);
	TreeNode* rcc = createLeftCloneTree(root->right);

	TreeNode* nn = new TreeNode(root->data);
	nn->left = lcc;
	root->left = nn;
	root->right = rcc;
	return root;
}

void display(TreeNode* root){
	if(root == nullptr){
		return;
	}
	if(root->left){
		cout << root -> left->data;
	} else {
		cout << ".";
	}

	cout << "<-" << root->data<<"->";
	
	if(root->right){
		cout << root -> right->data;
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
	TreeNode * root = takeInput();
	createLeftCloneTree(root);
	display(root);
}