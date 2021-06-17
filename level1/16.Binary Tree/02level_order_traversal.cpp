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

void levelOrder(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);

	while(q.size()){
		int sz = q.size();

		for(int i = 0 ; i < sz ; i++){
			auto front = q.front();
			q.pop();

			cout << front->data << " ";

			if(front->left) q.push(front->left);
			if(front->right) q.push(front->right);
		}
		cout << endl;
	}
}

int main(){
	int n;
	cin >> n;
	TreeNode * root = takeInput();
	
	levelOrder(root);
}