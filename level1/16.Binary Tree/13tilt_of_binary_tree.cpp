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

static int tilt = 0;
int tiltOfTree(TreeNode* root){
	if(!root) return 0;

	int ls = tiltOfTree(root->left);
	int rs = tiltOfTree(root->right);

	tilt += abs(ls - rs);
	return ls + rs + root->data;
}

int main(){
	int n;
	cin >> n;
	TreeNode * root = takeInput();
	tiltOfTree(root);
	cout << tilt;
}