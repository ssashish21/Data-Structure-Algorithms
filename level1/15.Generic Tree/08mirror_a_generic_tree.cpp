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


void mirror(TreeNode* root){
    for(TreeNode* child : root->children){
        mirror(child);
    }
    
    reverse(root->children.begin() , root->children.end());
    /*
    int l = 0;
    int r = root->children.size() - 1;

    while(l < r){
        auto temp = root->children[l];
        root->children[l] = root->children[r];
        root->children[r] = temp;

        l++;
        r--;
    }
    */
}

int main(){
    TreeNode* root = constructTree();
    display(root);
    mirror(root);
    display(root);
    delete root;
}