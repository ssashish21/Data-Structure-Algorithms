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


void removeLeaves(TreeNode* root){
    for(int i = root->children.size() - 1 ; i >= 0 ; i--){
        TreeNode* child = root->children[i];
        if(child->children.size() == 0){
            for(int j = i ; j < root->children.size() ; j++)
                root->children[j] = root->children[j+1];
                root->children.pop_back();
        }
    }
    for(auto child : root->children){
        removeLeaves(child);
    } 
}



int main(){
    TreeNode* root = constructTree();
    removeLeaves(root);
    display(root);
    delete root;
}