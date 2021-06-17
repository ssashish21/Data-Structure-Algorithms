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

int height(TreeNode* root){
	if(root == nullptr){
		return -1;
	}

	int lh = height(root->left);
	int rh = height(root->right);

	return max(lh , rh) + 1;
}

int diameter(TreeNode* root){
	if(root == nullptr){
		return 0;
	}

	int ld = diameter(root->left);
	int rd = diameter(root->right);

	int faith = height(root->left) + height(root->right) + 2;
	int dia = max({faith , ld , rd});

	return dia;
}

class DiaPair{
public:
	int dia;
	int hei;

	DiaPair(){

	}

	DiaPair(int d , int h){
		dia = d;
		hei = h;
	}
};

DiaPair* diameter2(TreeNode* root){
	if(root == nullptr){
		DiaPair* bp = new DiaPair(0 , -1);
		return bp;
	}

	DiaPair* lp = diameter2(root->left);
	DiaPair* rp = diameter2(root->right);

	DiaPair* mp = new DiaPair();
	mp->hei = max(lp->hei , rp->hei) + 1;

	int f = lp->hei + rp->hei + 2;
	mp->dia = max({f , lp->dia , rp->dia});

	return mp;
}

int main(){
	int n;
	cin >> n;
	TreeNode * root = takeInput();
	DiaPair *dp = diameter2(root);
	cout << dp->dia << endl;
}