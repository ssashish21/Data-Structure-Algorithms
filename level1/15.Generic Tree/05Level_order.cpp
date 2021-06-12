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

void levelorder(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);

	while(q.size() > 0){
		auto front = q.front();
		q.pop();

		cout << front->data << " ";
		for(int i = 0 ; i < front->children.size() ; i++){
			q.push(front->children[i]);
		}
	}
	cout << ".";
}

int main(){
	TreeNode* root = constructTree();
	levelorder(root);
}