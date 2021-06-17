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

TreeNode* BackFromLeftCloneTreeToNormal(TreeNode* root){
	if(root == NULL){
		return NULL;
	}

	TreeNode* ltc = BackFromLeftCloneTreeToNormal(root->left->left);
	TreeNode* rtc = BackFromLeftCloneTreeToNormal(root->right);

	root->left = ltc;
	root->right = rtc;
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
	root = BackFromLeftCloneTreeToNormal(root);
	display(root);
}