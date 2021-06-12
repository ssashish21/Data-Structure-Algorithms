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

static int msn = 0;
static int ms = INT_MIN;

int MaximumSumSubtree(TreeNode * root){
    int sum = 0;
    for(auto child : root->children){
        int csum = MaximumSumSubtree(child);
        sum += csum;
    }

    sum += root->data;

    if(sum > ms){
        ms = sum;
        msn = root->data;
    }
    return sum;
}

int main(){
    TreeNode* root = constructTree();
    
    MaximumSumSubtree(root);

    cout << msn <<"@" << ms << endl;

    delete root;
}