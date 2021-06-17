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

void PreInPost(TreeNode* root){
	stack<pair<TreeNode*,int>> st;
	st.push({root , 1});

	vector<int> pre , in , post;

	while(st.size() > 0){
		auto &top = st.top();

		if(top.second == 1){
			pre.push_back(top.first->data);
			top.second++;

			if(top.first->left){
				st.push({top.first->left , 1});
			}
		} else if(top.second == 2){
			in.push_back(top.first->data);
			top.second++;

			if(top.first->right){
				st.push({top.first->right , 1});
			}
		} else {
			post.push_back(top.first->data);
			st.pop();
		}
	}

	for(auto x : pre) cout <<x<<" "; cout << endl;
	for(auto x : in) cout <<x<<" "; cout << endl;
	for(auto x : post) cout <<x<<" "; cout << endl;
}

int main(){
	int n;
	cin >> n;
	TreeNode * root = takeInput();
	
	PreInPost(root);
}