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


int size(BSTNode* root){
	if(!root) return 0;

	int ls = size(root->left);
	int rs = size(root->right);

	return ls + rs + 1;
}

int sum(BSTNode* root){
	if(!root) return 0;

	return root->data + 
			sum(root->left) +
			sum(root->right);
}

int max(BSTNode* root){
	if(root->right == nullptr){
		return root->data;
	}

	return max(root->right);
}

int min(BSTNode* root){
	if(root->left){
		return min(root->left);
	} else {
		return root->data;
	}
}

bool find(BSTNode* root , int key){
	if(!root) return false;
	if(root->data == key){
		return true;
	} else if(root->data > key){
		return find(root->left, key);
	} else {
		return find(root->right, key);
	}
}



int main(){
	int n;
	cin >> n;

	BSTNode* root = takeInput();
	int key;
	cin >> key;
	
	cout << size(root) << endl;
	cout << sum(root) << endl;
	cout << max(root) << endl;
	cout << min(root) << endl;
	string ok = find(root , key) ? "true" : "false";
	cout << ok;
}