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



TreeNode* linerize2(TreeNode* root){
    if(root->children.size() == 0){
        return root;
    }
    
    TreeNode* lkt = linerize2(root->children[root->children.size() - 1]);

    while(root->children.size() > 1){
        TreeNode* last = root->children[root->children.size() - 1];
        root->children.pop_back();
        TreeNode* sl = root->children[root->children.size() - 1];
        TreeNode* slkt = linerize2(sl);
        slkt->children.push_back(last);
    }
    return lkt;
}



int main(){
    TreeNode* root = constructTree();
    linerize2(root);
    display(root);
    delete root;
}