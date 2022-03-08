#include<bits/stdc++.h>
using namespace std;


struct BinarySearchTreeNode {
    int val;
    BinarySearchTreeNode *left;
    BinarySearchTreeNode *right;
    BinarySearchTreeNode() : val(0),left(nullptr),right(nullptr){}
    BinarySearchTreeNode(int val) : val(val),left(nullptr),right(nullptr) {}
    BinarySearchTreeNode(int val,BinarySearchTreeNode *left, BinarySearchTreeNode *right) : val(val),left(left),right(right) {}
};
BinarySearchTreeNode *root;

void insert(int val) {
    queue<BinarySearchTreeNode *> q;
    q.push(root);
    while(!q.empty()) {
        BinarySearchTreeNode *curNode = q.front();
        q.pop();

        if(val < curNode->val){
            if(curNode->left != nullptr) {
                q.push(curNode -> left);
            }
            else {
                curNode->left = new BinarySearchTreeNode(val);
                return ;
            }
        }
        else if(val > curNode->val) {
            if(curNode->right != nullptr) {
                q.push(curNode->right);
            }
            else {
                curNode->right = new BinarySearchTreeNode(val);
                return;
            }
        }
    }
}

void printBinarySearchTreeLevelWise() {
    vector<vector<BinarySearchTreeNode *>> level;
    queue<BinarySearchTreeNode *>q;
    q.push(root);
    
    while(!q.empty()) {
        int nodeCounter = q.size();
        vector<BinarySearchTreeNode *> l;
        while(nodeCounter > 0) {
            BinarySearchTreeNode *curNode = q.front();
            l.push_back(curNode);
            q.pop();
            if(curNode->left != nullptr) {
                q.push(curNode->left);
            }
            if(curNode->right != nullptr) {
                q.push(curNode->right);
            }
            nodeCounter--;
        }
        level.push_back(l);
    }

    for(auto lev:level) {
        for(auto l:lev) {
            cout << l->val <<" ";
        }
        cout<<endl;
    }
}


void leafNodes() {
    vector<BinarySearchTreeNode *>leaves;
    queue<BinarySearchTreeNode*>q;
    q.push(root);
    while(!q.empty()){
        BinarySearchTreeNode* temp = q.front();
        q.pop();
        if(temp->left == nullptr && temp->right == nullptr) {
            leaves.push_back(temp);
        }
        if(temp->left != nullptr) {
            q.push(temp->left);
        }
        if(temp->right != nullptr) {
            q.push(temp->right);
        }
    }

    cout<<"Leaf nodes are: ";
    for(auto l:leaves) {
        cout<<l->val<<" ";
    }
}

void printInOrderTraversal(BinarySearchTreeNode *temp) {
    if(temp == nullptr) {
        return;
    }
    printInOrderTraversal(temp->left);
    cout << temp->val <<" ";
    printInOrderTraversal(temp->right);
}

void printPreOrderTraversal(BinarySearchTreeNode *temp) {
    if(temp == nullptr) {
        return;
    }
    cout << temp->val <<" ";
    printPreOrderTraversal(temp->left);
    printPreOrderTraversal(temp->right);
}

void printPostOrderTraversal(BinarySearchTreeNode *temp) {
    if(temp == nullptr) {
        return;
    }
    printPostOrderTraversal(temp->left);
    printPostOrderTraversal(temp->right);
    cout<<temp->val<<" ";
}

BinarySearchTreeNode* first=nullptr;
BinarySearchTreeNode* second=nullptr;
void recoverBinarySearchTree(BinarySearchTreeNode* temp) {
    if(temp == nullptr) {
        return;
    }
    auto leftTree = temp->left;
    auto rightTree = temp->right;
    recoverBinarySearchTree(leftTree);

    if(first==nullptr && leftTree->val > temp->val) {
        first = leftTree;
    }

    if(first != nullptr && rightTree->val < temp->val) {
        second = temp;
        return;
    }

    recoverBinarySearchTree(temp->right);
}

BinarySearchTreeNode* getMinValue(BinarySearchTreeNode* temp1) {
    auto temp = temp1;
    while(temp != nullptr && temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}


BinarySearchTreeNode* deleteNode(BinarySearchTreeNode* root,int val) {
    if(root == nullptr) {
        return nullptr;
    }
    if(val < root->val) {
        root->left = deleteNode(root->left,val);
    }
    else if(val > root->val) {
        root->right = deleteNode(root->right,val);
    }
    else if(val == root->val) {
        //case 1==> leaf node to be deleted
        if(root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }
        //case 2 ==> left tree is null
        else if(root->left == nullptr) {
            auto newNode = root->right;
            free(root);
            return newNode;
        }
        //case 3 ==> right tree is null
        else if(root->right == nullptr) {
            auto newNode = root->left;
            free(root);
            return newNode;
        }

        auto tempNode = getMinValue(root->right);
        root->val = tempNode->val;
        root->right = deleteNode(root->right,tempNode->val);

    }

    return root;
}

int main() {
    // root = new BinarySearchTreeNode(10);
    // insert(5);
    // insert(3);
    // insert(7);
    // insert(15);
    // insert(13);
    // insert(18);
    // printBinarySearchTreeLevelWise();
    // cout<<endl<<endl;
    // root = deleteNode(root,10);
    // printBinarySearchTreeLevelWise();
    return 0;
}