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

static int _ceil;
static int _floor;

void CeilAndFloor(TreeNode* root , int val){
    //calculate ceil
    if(root->data > val){
        if(root->data < _ceil)
            _ceil = root->data;
    }

    //calculate floor
    if(root->data < val){
        if(root->data > _floor)
            _floor = root->data;
    }

    for(auto child : root->children){
        CeilAndFloor(child , val);
    }
}


int main(){
    TreeNode* root = constructTree();
    int val;
    cin >> val;

    _ceil = INT_MAX;
    _floor = INT_MIN;
    
    CeilAndFloor(root , val);

    cout << "CEIL = " << _ceil << endl;
    cout << "FLOOR = " << _floor << endl;

    delete root;
}