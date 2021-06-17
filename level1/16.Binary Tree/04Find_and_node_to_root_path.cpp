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

vector<int> path;
bool ntrPATH(TreeNode* root , int key){
	if(!root) return false;

	if(root->data == key){
		path.push_back(root->data);
		return true;
	}

	bool isinleft = ntrPATH(root->left , key);
	if(isinleft) {
		path.push_back(root->data);
		return true;
	}

	bool isinright = ntrPATH(root->right , key);
	if(isinright){
		path.push_back(root->data);
		return true;
	}

	return false;
}

int main(){
	int n;
	cin >> n;
	TreeNode * root = takeInput();
	int key;
	cin >> key;

	path.clear();

	string res = find(root , key) ? "true" : "false";
	ntrPATH(root , key);
	cout << res << endl;

	cout<<"[";
	for(int i = 0 ; i < path.size() ; i++){
		cout << path[i];
		if(i != path.size() - 1)
			cout << ", ";
	}
	cout <<"]";
}