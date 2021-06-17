#include<iostream>
#include<stack>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
int max(int a , int b){
    return a > b ? a : b;
}
int min(int a , int b){
    return a > b ? b : a;
}
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~Node(){
            delete left;
            delete right;
        }
};

class Pair{
    public: 
        Node* node;
        int state;

        Pair(Node* node , int state){
            this->node = node;
            this->state = state;
        }
};

Node* constructTree(vector<int>& ar){
    Node* root = new Node(ar[0]);
    Pair* rtp = new Pair(root , 1);

    stack<Pair*> st;
    st.push(rtp);

    int idx = 0;
    while(st.size() > 0){
        Pair* top = st.top();
        if(top->state == 1){
            idx++;
            if(ar[idx] != INT_MIN){
                top->node->left = new Node(ar[idx]);
                Pair* lp = new Pair(top->node->left , 1);
                st.push(lp);
            } else {
                top->node->left = NULL;
            }
            top->state++;
        }
        else if(top->state == 2){
            idx++;
            if(ar[idx] != INT_MIN){
                top->node->right = new Node(ar[idx]);
                Pair* rp = new Pair(top->node->right , 1);
                st.push(rp);
            } else {
                top->node->right = NULL;
            }
            top->state++;
        } 
        else {
            st.pop();
        }
    }
    return root;
}

int sizeOfTree(Node* root){
    if(root == NULL) return 0;
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}

int sumOfTree(Node* root){
    if(root == NULL) return 0;
    return root->data + sumOfTree(root->left)  + sumOfTree(root->right);
}

int maxInTree(Node* root){
    if(root == NULL) return INT_MIN;
    int lm = maxInTree(root->left);
    int rm = maxInTree(root->right);
    int tm = max(root->data , max(lm , rm));
    return tm;
}

int height(Node* root){
    if(root == NULL){
        return -1;
    } 
    return 1 + max(height(root->left) , height(root->right));
}

void levelOrder(Node* root){
    queue<Node*> mq;
    mq.push(root);

    while(mq.size() > 0){
        int count = mq.size();
        for(int i = 0 ; i < count ; i++){
            Node* front = mq.front();
            mq.pop();
            cout<<front->data<<" ";
            if(front->left) mq.push(front->left);
            if(front->right) mq.push(front->right);
        }
        cout<<endl;
    }
}

void preInPost(Node* root){
    stack<Pair*> st;
    Pair* rtp = new Pair(root , 1);
    st.push(rtp);
    vector<int> pre , in , post;

    while(st.size() > 0){
        Pair* top = st.top();
        if(top->state == 1){
            pre.push_back(top->node->data);
            top->state++;
            if(top->node->left){
                Pair* ln = new Pair(top->node->left , 1);
                st.push(ln);
            }
        } else if(top->state == 2){
            in.push_back(top->node->data);
            top->state++;
            if(top->node->right){
                Pair* rn = new Pair(top->node->right , 1);
                st.push(rn);
            }
        } else {
            post.push_back(top->node->data);
            st.pop();
        }
    }
    for(int it : pre) cout<<it<<" ";
    cout<<endl;
    for(int it : in) cout<<it<<" ";
    cout<<endl;
    for(int it : post) cout<<it<<" "; 
}

bool find(Node* root , int val){
    if(root == NULL) return false;

    if(root->data == val) return true;

    bool isinlc = find(root->left , val);
    if(isinlc) return true;

    bool isinrc = find(root->right , val);
    if(isinrc) return true;

    return false;
}
vector<Node*> ntrpath;
bool nodeRootPath(Node* root , int val){
    if(root == NULL) return false;

    if(root->data == val){
        ntrpath.push_back(root);
        return true;
    }

    int isinlc = nodeRootPath(root->left , val);
    if(isinlc){
        ntrpath.push_back(root);
        return true;
    }

    int isinrc = nodeRootPath(root->right , val);
    if(isinrc){
        ntrpath.push_back(root);
        return true;
    }

    return false;
}

void printkLevelDown(Node* root , int k , Node* block){
    if(root == NULL || k < 0 || root == block) return;

    if(k == 0) cout<<root->data<<endl;

    printkLevelDown(root->left , k-1 , block);
    printkLevelDown(root->right , k - 1 , block);
}

void printkDistanceAway(Node* root , int val , int k){
    ntrpath = {};
    nodeRootPath(root , val);
    for(int i = 0 ; i < ntrpath.size() ; i++){
        printkLevelDown(ntrpath[i] , k - i , i == 0 ? NULL : ntrpath[i-1]);
    }
}

void pathToleafFromRoot(Node* root , vector<int> &path ,int sum, int lo , int hi){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        sum+= root->data;
        path.push_back(root->data);
        if(sum >= lo && sum <= hi){
            for(int it : path){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        sum-=root->data;
        path.pop_back();
        return;
    }
    sum = sum + root->data ;
    path.push_back(root->data);
    pathToleafFromRoot(root->left ,  path ,sum,lo , hi);
    pathToleafFromRoot(root->right , path ,sum, lo , hi);
    sum-=root->data;
    path.pop_back();
}

void display(Node* node) {
    if (node == NULL) {
      return;
    }
    if(node->left == NULL){
        cout<<". ";
    }else{
        cout<<node->left->data<<" ";
    }
    cout<<"<- "<<node->data<<" -> ";
    if(node->right == NULL){
        cout<<".";
    }else{
        cout<<node->right->data;
    }
  cout<<endl;
    display(node->left);
    display(node->right);
}

Node* createLeftCloneTree(Node* root){
    if(root == NULL){
        return NULL;
    }

    Node* lcc = createLeftCloneTree(root->left);
    Node* rcc = createLeftCloneTree(root->right);

    Node* nn = new Node(root->data);
    nn->left = lcc;
    root->left = nn;
    root->right = rcc;

    return root;
}

Node* transBackFromLeftClonedTree(Node* root){
    if(root == NULL){
        return NULL;
    }

    Node* ltc = transBackFromLeftClonedTree(root->left->left);
    Node* rtc = transBackFromLeftClonedTree(root->right);

    root->left = ltc;
    root->right = rtc;
    return root;
}

void printSingleChildNodes(Node* root){
    if(root == NULL)
        return;
    
    if(root->left != NULL && root->right == NULL){
        cout<<root->left->data<<endl;
    }

    if(root->left == NULL && root->right != NULL){
        cout<<root->right->data<<endl;
    }
    
    printSingleChildNodes(root->left);
    printSingleChildNodes(root->right);
}

Node* removeLeaves(Node* root){
    if(root == NULL)
        return NULL;
    
    if(root->left == NULL && root->right == NULL)
        return NULL;

    root->left = removeLeaves(root->left);
    root->right = removeLeaves(root->right);

    return root;
}

int diameter1(Node* root){

    if(root == NULL) return 0;

    int ld = diameter1(root->left);
    int rd = diameter1(root->right);

    int f = height(root->left) + height(root->right) + 2;
    int dia = max(max(ld , rd) , f);
    return dia;
}

class Diapair{
    public:
    int dia;
    int ht;
};

Diapair* diameter2(Node* root){
    if(root == NULL){
        Diapair *bp = new Diapair();
        bp->ht = -1;
        bp->dia = 0;
        return bp;
    }

    Diapair *lp = diameter2(root->left);
    Diapair *rp = diameter2(root->right);

    Diapair *mp = new Diapair();
    mp->ht = max(lp->ht , rp->ht) + 1;
    
    int f = lp->ht + rp->ht + 2;
    mp->dia = max(max(lp->dia , rp->dia) , f);

    return mp;
}

static int tilt = 0;
int tiltOfTree(Node* root){
    if(root == NULL)
        return 0;

    int ls = tiltOfTree(root->left);
    int rs = tiltOfTree(root->right);
    
    int ltilt = abs(ls - rs);
    tilt += ltilt;

    int ts = ls + rs + root->data;
    return ts;
}

class BSTpair{
    public:
        bool isBst;
        int mn;
        int mx;

        BSTpair(bool isBst , int mn , int mx){
            this->isBst = isBst;
            this->mn = mn;
            this->mx = mx;
        }

        BSTpair(){

        }
};

BSTpair* isTreeBST(Node* root){
    if(root == NULL){
        BSTpair* bp = new BSTpair(true , INT_MAX , INT_MIN);
        return bp; 
    }

    BSTpair* lp = isTreeBST(root->left);
    BSTpair* rp = isTreeBST(root->right);

    BSTpair* mp = new BSTpair();
    mp->isBst = lp->isBst && rp->isBst && (root->data >= lp->mx && root->data <= rp->mn);
    mp->mn = min(root->data , min(lp->mn , rp->mn));
    mp->mx = max(root->data , max(lp->mx , rp->mx));

    return mp;
}

static bool isbal;
int isTreeBal(Node* root){
    
    if(root == NULL) return -1;

    int lh = isTreeBal(root->left);
    int rh = isTreeBal(root->right);

    int gap = abs(lh - rh);
    if(gap > 1) isbal = false;

    int mh = max(lh , rh) + 1;
    return mh;
}

class BalPair{
    public:
        bool isBal;
        int ht;
};

BalPair* isBALTree(Node* root){
    if(root == NULL){
        BalPair* bp = new BalPair();
        bp->ht = 0;
        bp->isBal = true;
        return bp;
    }

    BalPair* lp = isBALTree(root->left);
    BalPair* rp = isBALTree(root->right);

    BalPair* mp = new BalPair();
    mp->isBal = lp->isBal && rp->isBal && (abs(lp->ht - rp->ht) <= 1);
    mp->ht = max(lp->ht , rp->ht) + 1;
    return mp;
}

class lBSTpair{
    public:
        bool isBst;
        int mn;
        int mx;
        Node* lroot;
        int size;
        lBSTpair(bool isBst , int mn , int mx , Node* lroot , int size){
            this->isBst = isBst;
            this->mn = mn;
            this->mx = mx;
            this->lroot = lroot;
            this->size = size;
        }
        lBSTpair(){

        }
};
lBSTpair* largestBstSubtree(Node* root){

    if(root == NULL){
        lBSTpair* bp = new lBSTpair(true , INT_MAX , INT_MIN , NULL , 0);
        return bp; 
    }

    lBSTpair* lp = largestBstSubtree(root->left);
    lBSTpair* rp = largestBstSubtree(root->right);

    lBSTpair* mp = new lBSTpair();
    mp->isBst = lp->isBst && rp->isBst && (root->data >= lp->mx && root->data <= rp->mn);
    mp->mn = min(root->data , min(lp->mn , rp->mn));
    mp->mx = max(root->data , max(lp->mx , rp->mx));

    if(mp->isBst == true){
        mp->lroot = root;
        mp->size = lp->size + rp->size + 1;
    } else if(lp->size > rp->size){
        mp->lroot = lp->lroot;
        mp->size = lp->size;
    } else {
        mp->lroot = rp->lroot;
        mp->size = rp->size;
    }

    return mp;
}

int main(){
    int n ; cin >> n;
    string val;
    vector<int> ar(n);
    for(int i = 0 ; i < n ; i++){
        cin>>val;
        if(val == "n") ar[i] = INT_MIN;
        else ar[i] = stoi(val);
    }  
    Node* root = constructTree(ar);
    lBSTpair* p = largestBstSubtree(root);
    cout<<p->lroot->data<<"@"<<p->size;

    delete root;
}