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

class Pair{
    public:
    TreeNode* node;
    int state;

    Pair(TreeNode* node , int state){
        this->node = node;
        this->state = state;
    }
};

void ittrPreAndPost(TreeNode* root){
    stack<Pair*> st;
    Pair *p = new Pair(root , -1);
    st.push(p);

    vector<int> pre;
    vector<int> post;

    while(st.size() > 0){
        Pair *top = st.top();
        if(top->state == -1){
             pre.push_back(top->node->data);
             top->state++;
        } else if(top->state == top->node->children.size()){
            post.push_back(top->node->data);
            st.pop();
        } else {
            Pair *cp = new Pair(top->node->children[top->state] , -1);
            st.push(cp);

            top->state++;
        }
    }
    for(int num : pre){
        cout<<num<<" ";
    }
    cout<<endl;
    for(int num : post){
        cout<<num<<" ";
    }
}

int main(){
    TreeNode* root = constructTree();
    
    ittrPreAndPost(root);

    delete root;
}