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

static TreeNode* predecessor;
static TreeNode* successor;
static int state;

void PredecessorAndSucessor(TreeNode* root , int val){
    if(state == 0){
        if(root->data == val)
            state = 1;
        else
            predecessor = root;
    } else if(state == 1){
        state = 2;
        successor = root;
    }

    for(auto child : root->children){
        PredecessorAndSucessor(child , val);
    }
}



int main(){
    TreeNode* root = constructTree();
    int val;
    cin >> val;

    predecessor = nullptr;
    successor = nullptr;
    state = 0;
    
    PredecessorAndSucessor(root , val);
    
    if(predecessor == NULL){
        cout<<"Predecessor = Not found"<<endl;
    } else {
        cout<<"Predecessor = " << predecessor->data<<endl;
    }

    if(successor == NULL){
        cout<<"Successor = Not found"<<endl;
    } else {
        cout<<"Successor = " << successor->data<<endl;
    }

    delete root;
}