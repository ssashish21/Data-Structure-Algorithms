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

bool isMirrorTree(TreeNode* r1 , TreeNode* r2){
    if(r1->children.size() != r2->children.size()){
        return false;
    }

    for(int i = 0 ; i < r1->children.size() ; i++){
        auto c1 = r1->children[i];
        auto c2 = r2->children[r2->children.size() - i - 1];

        if(isMirrorTree(c1 , c2) == false)
            return false;
    }
    return true;
}



int main(){
    TreeNode* root1 = constructTree();
    TreeNode* root2 = constructTree();
    
    bool res = isMirrorTree(root1 , root2);
    if(res)
        cout <<"true";
    else
        cout << "false";

    delete root1;
    delete root2;
}