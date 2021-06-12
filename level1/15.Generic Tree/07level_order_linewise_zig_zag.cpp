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

void levelorderLinewiseZigZag(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);
	bool l_to_r = true;

	while(q.size() > 0){
		int sz = q.size();
		
		vector<int> level;
		for(int i = 0 ; i < sz ; i++){
			auto front = q.front();
			q.pop();

			level.push_back(front->data);

			for(int i = 0 ; i < front->children.size() ; i++){
				q.push(front->children[i]);
			}
		}
		if(l_to_r){
			for(int i = 0 ; i < level.size() ; i++){
				cout << level[i] << " ";
			}
		} else {
			for(int i = level.size() - 1 ; i >= 0 ; i--){
				cout << level[i] << " ";
			}
		}
		l_to_r = l_to_r ^ 1;
		cout << endl;
	}
}

int main(){
	TreeNode* root = constructTree();
	levelorderLinewiseZigZag(root);
}