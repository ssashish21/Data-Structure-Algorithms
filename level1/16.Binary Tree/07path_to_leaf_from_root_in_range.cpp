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

void pathToLeafFromRoot(TreeNode * root , vector<int> &path , int sum, int lo , int hi){
	if(root == nullptr) return;
	if(root->left == nullptr && root->right == nullptr){
		sum += root->data;
		path.push_back(root->data);
		if(sum >= lo && sum <= hi){
			for(auto x : path)
				cout << x << " ";
			cout << endl;
		}
		sum -= root->data;
		path.pop_back();
		return;
	}

	sum += root->data;
	path.push_back(root->data);
	pathToLeafFromRoot(root->left , path , sum , lo , hi);
	pathToLeafFromRoot(root->right , path , sum , lo , hi);
	sum -= root->data;
	path.pop_back();
}

int main(){
	int n;
	cin >> n;
	TreeNode * root = takeInput();
	int lo , hi;
	cin >> lo >> hi;
	vector<int> path;

	pathToLeafFromRoot(root ,path, 0 , lo, hi);
}