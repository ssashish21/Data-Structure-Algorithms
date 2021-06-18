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

void display(BSTNode* root){
	if(!root){
		return;
	}

	if(root->left){
		cout << root->left->data;
	} else {
		cout << ".";
	}
	cout <<" <- " << root->data << " -> ";
	if(root->right){
		cout << root->right->data;
	} else {
		cout << ".";
	}
	cout << endl;

	display(root->left);
	display(root->right);
}

static int sumOfLargerNodes = 0;
void replaceWithSumOfLarger(BSTNode* root){
	if(!root) return;

	replaceWithSumOfLarger(root->right);

	int oldData = root->data;
	root->data = sumOfLargerNodes;
	sumOfLargerNodes += oldData;

	replaceWithSumOfLarger(root->left);
}


int main(){
	int n;
	cin >> n;

	BSTNode* root = takeInput();

	replaceWithSumOfLarger(root);
	display(root);
}