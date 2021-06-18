#include<bits/stdc++.h>
using namespace std;

class BSTNode{
public:
	int data;
	BSTNode* left;
	BSTNode* right;

	BSTNode(){
		data = 0;
		left = nullptr;
		right = nullptr;
	}

	BSTNode(int data){
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}

	~BSTNode(){
		delete left;
		delete right;
	}
};

BSTNode* takeInput(){
	string rootData;
	cin >> rootData;

	if(rootData == "n"){
		return nullptr;
	}

	BSTNode* root = new BSTNode(stoi(rootData));

	root->left = takeInput();
	root->right = takeInput();

	return root;
}


bool find(BSTNode* root , int val){
	if(!root) return false;

	if(root->data > val){
		return find(root->left , val);
	} else if(root->data < val){
		return find(root->right , val);
	} else {
		return true;
	}
}

void tarSumBST(BSTNode* root , BSTNode* node , int tar){
	if(!node) return;

	tarSumBST(root , node->left , tar);

	int comp = tar - node->data;

	if(node->data < comp){
		if(find(root , comp)){
			cout << node->data << " " << comp << endl;
		}
	}

	tarSumBST(root , node->right , tar);
}

int main(){
	int n;
	cin >> n;

	BSTNode* root = takeInput();
	
	int tar;
	cin >> tar;

	tarSumBST(root,root,tar);
}