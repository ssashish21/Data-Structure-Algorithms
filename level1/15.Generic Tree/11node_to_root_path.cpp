#include "bits/stdc++.h"
using namespace std;

class TreeNode{
    public:
    int data;
    vector<TreeNode*> children;

    TreeNode(int data){
        this->data = data;
    }

    ~TreeNode(){
        for(int i = 0 ; i < children.size() ; i++){
            delete children[i];
        }
    }
};

TreeNode* constructTree(){
    TreeNode* root = NULL;
    int n , val;
    cin>>n;
    stack<TreeNode*> pendingNodes;

    for(int i = 0 ; i < n ; i++){
        cin>>val;
        if(val == -1){
            pendingNodes.pop();
        } else{
            TreeNode* newTreeNode = new TreeNode(val);
            
            if(pendingNodes.size() > 0){
                pendingNodes.top()->children.push_back(newTreeNode);
            } else {
                root = newTreeNode;
            }
            pendingNodes.push(newTreeNode);
        }
    }
    return root;
}

void display(TreeNode* root){
    cout<<root->data<<" -> ";
    for(TreeNode* child : root->children){
        cout<<child->data<<", ";
    }
    cout<<"."<<endl;
    for(TreeNode* child : root->children){
        display(child);
    }
}

vector<int> NTRpath(TreeNode* root , int val){
    if(root->data == val){
        return {root->data};
    }

    for(auto child : root->children){
        vector<int> ptc = NTRpath(child , val);
        if(ptc.size()){
            ptc.push_back(root->data);
            return ptc;
        }
    }
    return {};
}



int main(){
    TreeNode* root = constructTree();
    int k;
    cin >> k;
    vector<int> p = NTRpath(root , k);

    cout <<"[";
    for(int i = 0 ; i < p.size() ; i++){
        cout << p[i];
        if(i != p.size() - 1)
            cout << ", ";
    }
    cout <<"]";

    delete root;
}