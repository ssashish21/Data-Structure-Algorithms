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

bool find(TreeNode* root , int key){
	if(!root) return false;

	if(root->data == key){
		return true;
	}

	bool isinleft = find(root->left , key);
	if(isinleft) return true;

	bool isinright = find(root->right , key);
	if(isinright) return true;

	return false;
}

vector<TreeNode*> path;
bool ntrPATH(TreeNode* root , int key){
	if(!root) return false;

	if(root->data == key){
		path.push_back(root);
		return true;
	}

	bool isinleft = ntrPATH(root->left , key);
	if(isinleft) {
		path.push_back(root);
		return true;
	}

	bool isinright = ntrPATH(root->right , key);
	if(isinright){
		path.push_back(root);
		return true;
	}

	return false;
}

void printKlevelDown(TreeNode* root , int k , TreeNode* blocker){
	if(!root || k < 0 || root == blocker) return;
	if(k == 0) cout << root->data <<endl;

	printKlevelDown(root->left , k - 1 , blocker);
	printKlevelDown(root->right , k - 1 , blocker); 
}


void printKdistanceAway(TreeNode* root , int key , int k){
	path.clear();
	ntrPATH(root , key);

	for(int i = 0 ; i < path.size() ; i++){
		TreeNode* blocker = (i == 0) && i <= k ? nullptr : path[i-1];
		printKlevelDown(path[i] , k - i , blocker);
	}
}


int main(){
	int n;
	cin >> n;
	TreeNode * root = takeInput();
	int key , k;
	cin >> key >> k;

	printKdistanceAway(root , key , k);
}