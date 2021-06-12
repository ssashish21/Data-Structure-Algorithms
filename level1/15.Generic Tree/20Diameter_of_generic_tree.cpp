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

static int dia = 0;

int diaRetHeight(TreeNode * root){
    int dch = -1;
    int sdch = -1;

    for(auto child : root->children){
        int ch = diaRetHeight(child);
        if(ch > dch){
            sdch = dch;
            dch = ch;
        } else if(ch > sdch){
            sdch = ch;
        }
    }

    int cand = dch + sdch  + 2;
    if(cand > dia){
        dia = cand;
    }
    return dch + 1;
}

int main(){
    TreeNode* root = constructTree();
    
    diaRetHeight(root);

    cout << dia;

    delete root;
}