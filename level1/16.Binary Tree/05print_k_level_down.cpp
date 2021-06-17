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

void printKlevelDown(TreeNode* root , int k){
	if(!root || k < 0) return;
	if(k == 0) cout << root->data <<endl;

	printKlevelDown(root->left , k - 1);
	printKlevelDown(root->right , k - 1); 
}

int main(){
	int n;
	cin >> n;
	TreeNode * root = takeInput();
	int k;
	cin >> k;
	printKlevelDown(root , k);
}