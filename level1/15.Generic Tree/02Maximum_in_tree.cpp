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
	int n , val;
	cin >> n;
	stack<TreeNode*> pendingNodes;

	for(int i = 0 ; i < n ; i++){
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

int maximumInTree(TreeNode* root){
	if(root == nullptr){
		return 0;
	} 

	int maxinchild = INT_MIN;
	for(int i = 0 ; i < root->children.size() ; i++){
		maxinchild = max(maxinchild , maximumInTree(root->children[i]));
	}
	return max(maxinchild , root->data);
}

int main(){
	TreeNode* root = constructTree();
	cout << maximumInTree(root);
}