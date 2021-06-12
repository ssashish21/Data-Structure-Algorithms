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

void Traversal(TreeNode* root){
	cout << "Node Pre " << root->data << endl;
	for(auto c : root->children){
		cout << "Edge Pre "<<root->data << "--"<<c->data <<endl;
		Traversal(c);
		cout << "Edge Post "<<root->data << "--"<<c->data <<endl;
	}
	cout << "Node Post " << root->data << endl;
}

int main(){
	TreeNode* root = constructTree();
	Traversal(root);
}