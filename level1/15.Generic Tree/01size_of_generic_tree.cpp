#include "bits/stdc++.h"
using namespace std;

class TreeNode{
public:
	int data;
	vector<TreeNode*> children;

	TreeNode(int data){
		this->data = data;
	}

	~TreeNode(){
		for(int i = 0 ; i < children.size() ; i++){
			delete children[i];
		}
	}
};

TreeNode* constructTree(){
	TreeNode* root = nullptr;
    int nofNodes , val;
    cin >> nofNodes;

	stack<TreeNode*> pendingNodes;

	for(int i = 0 ; i < nofNodes ; i++){
		cin >> val;
		if(val == -1){
			pendingNodes.pop();
		} else {
			TreeNode* node = new TreeNode(val);
			if(pendingNodes.size() == 0){
				root = node;
			} else {
				pendingNodes.top()->children.push_back(node);
			}
			pendingNodes.push(node);
		} 
	}
	return root;
}

void displayTree(TreeNode * root){
	if(root == nullptr){
		return;
	}

	cout << root->data << " : ";
	for(int i = 0 ; i < root->children.size() ; i++){
		cout << root->children[i]->data << " , ";
	}
	cout << endl;
	for(int i = 0 ; i < root->children.size() ; i++){
		displayTree(root->children[i]);
	}
}

int sizeOfTree(TreeNode* root){
	if(root == nullptr){
		return 0;
	}

	int childsize = 0;
	for(int i = 0 ; i < root->children.size() ; i++){
		childsize += sizeOfTree(root->children[i]);
	}
	return childsize + 1;
}

int main(){
	TreeNode* root = constructTree();
	cout << sizeOfTree(root) << endl;
}