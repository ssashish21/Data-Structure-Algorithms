#include "bits/stdc++.h"
using namespace std;

template <typename T>
class TreeNode{
public:
	T data;
	vector<TreeNode*> children;

	TreeNode(T data){
		this->data = data;
	}
};


/*
//recursion
TreeNode<int>* takeInput(){
	int rootdata;
	cout << "Enter Data : ";
	cin >> rootdata;
	TreeNode<int>* root = new TreeNode<int>(rootdata);

	int n;
	cout << "Enter number of children of " << rootdata  << " ";
	cin >> n;

	for(int i = 0 ; i < n ; i++){
		TreeNode<int> * child = takeInput();
		root->children.push_back(child);
	}
	return root;
}
*/

TreeNode<int>* takeInputLevelWise(){
	int rootdata;
	cout << "Enter root data : ";
	cin >> rootdata;

	TreeNode<int>* root = new TreeNode<int>(rootdata);

	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0){
		TreeNode<int> * front = pendingNodes.front();
		pendingNodes.pop();

		cout << "Enter no of child of " << front->data << endl;
		int numchild;
		cin >> numchild;

		for(int i = 0 ; i < numchild ; i++){
			cout << "Enter data of " << i << "th child of " << front->data << endl;
			int childdata;
			cin >> childdata;

			TreeNode<int>*child = new TreeNode<int>(childdata);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

void printTree(TreeNode<int> * root){
	if(root == nullptr){
		return;
	}

	cout << root->data << " : ";
	for(auto child : root->children){
		cout << child->data << ",";
	}
	cout << endl;
	for(auto child : root->children){
		printTree(child);
	}
}

int main(){
	TreeNode<int>* root = takeInputLevelWise();
	printTree(root);
}