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

static int _floor;
static int factor;

void Floor(TreeNode* root , int val){
    //calculate floor
    if(root->data < val){
       _floor = max(_floor , root->data);
    }

    for(auto child : root->children){
        Floor(child , val);
    }
}

int kThLargest(TreeNode* root , int k){
    _floor = INT_MIN;
    factor = INT_MAX;

    for(int i = 0 ; i < k ; i++){
        Floor(root , factor);
        factor = _floor;
        _floor = INT_MIN;
    }
    return factor;
}


int main(){
    TreeNode* root = constructTree();
    int k;
    cin >> k;
    
    int res = kThLargest(root , k);
    cout << res;

    delete root;
}