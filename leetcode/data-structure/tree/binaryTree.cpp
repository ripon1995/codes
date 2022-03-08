#include<bits/stdc++.h>
using namespace std;

struct BinaryTree {
    int value;
    struct BinaryTree *left;
    struct BinaryTree *right;
    BinaryTree() : value(0),left(nullptr),right(nullptr){}
    BinaryTree(int val) : value(val),left(nullptr),right(nullptr){}
    BinaryTree(int val,BinaryTree *left,BinaryTree *right) : value(val),left(left),right(right){}
};
struct BinaryTree *root;

//using bfs
void binaryTreeLevelWiseTraversal(BinaryTree *root) {
    vector<vector<int>>level;
    queue<BinaryTree *>q;
    q.push(root);
    while(!q.empty()) {
        int nodeCount = q.size();
        vector<int>l;
        while(nodeCount > 0) {
            BinaryTree *temp = q.front();
            l.push_back(temp->value);
            q.pop();
            if(temp->left != nullptr) {
                q.push(temp->left);
            }
            if(temp->right != nullptr) {
                q.push(temp->right);
            }
            nodeCount--;
        }
        level.push_back(l);
    }

    for(auto lev:level) {
        for(auto l:lev) cout<<l<<" ";
        cout<<endl;
    }
}

void inOrderTraversal(BinaryTree * temp)
{
    if(temp==nullptr)return;
    inOrderTraversal(temp->left);
    cout<<temp->value<<" ";
    inOrderTraversal(temp->right);
}

void insertNewNode(int val) {
    queue<BinaryTree *>q;
    q.push(root);

    while(!q.empty()) {
        BinaryTree *temp = q.front();
        q.pop();
        if(temp->left != nullptr) {
            q.push(temp->left);
        }
        else {
            temp->left = new BinaryTree(val);
            return;
        }
        if(temp->right != nullptr) {
            q.push(temp->right);
        }
        else {
            temp->right = new BinaryTree(val);
            return;
        }
    }
}


int binaryTreeHeight (BinaryTree *temp) {
    if(temp ==  nullptr) {
        return 0;
    }
    int leftHeight = binaryTreeHeight(temp->left);
    int rightHeight = binaryTreeHeight(temp->right);
    return max(leftHeight,rightHeight) +1;
}

int totalNodeInBinaryTree(BinaryTree *temp) {
    if(temp == nullptr) {
        return 0;
    }
    return 1 + totalNodeInBinaryTree(temp->left) + totalNodeInBinaryTree(temp->right);
}
int result = 0;
void sumOfGrandParent(BinaryTree *temp) {
    if(temp == nullptr) {
        return;
    }
    if(temp->value%2 == 0) {
        if(temp->left != nullptr) {
            if(temp->left->left != nullptr) {
                result += temp->left->left->value;
            }
            if(temp->left->right != nullptr) {
                result += temp->left->right->value;
            }
            sumOfGrandParent(temp->left);
        }
        if(temp->right != nullptr) {
            if(temp->right->left != nullptr) {
                result += temp->right->left->value;
            }
            if(temp->right->right != nullptr) {
                result += temp->right->right->value;
            }
            sumOfGrandParent(temp->right);
        }
    }
}

int search(vector<int>inOrder,int start,int end,int val) {
    int i;
    for(i=start;i<=end;i++) {
        if(inOrder[i] == val) {
            break;
        }
    }
    return i;
}

BinaryTree* constructBinaryTreFromPreorderAndInorderTraversal(vector<int>inOrder,vector<int>preOrder,int start,int end) {
     static int preIndex = 0;
    if(start > end) {
        return nullptr;
    }

    BinaryTree* newNode = new BinaryTree(preOrder[preIndex++]);
    if(start == end) {
        return newNode;
    }
    int inIndex = search(inOrder,start,end,newNode->value);

    newNode->left = constructBinaryTreFromPreorderAndInorderTraversal(inOrder,preOrder,start,inIndex-1);
    newNode->right = constructBinaryTreFromPreorderAndInorderTraversal(inOrder,preOrder,inIndex+1,end);
    return newNode;
}

int getInorderIndex(vector<int>inorder,int inorderStart,int inorderEnd,int val) {
    int i;
    for(i=inorderStart;i<=inorderEnd;i++) {
        if(inorder[i] == val) {
            break;
        }
    }
    return i;
}

BinaryTree* constructBinaryTreeFromInorderAndPostOrderTraversal(vector<int>inorder,vector<int>preorder,int inorderStart,int inorderEnd){
    static int preorderIndex = preorder.size()-1;
    if(inorderStart > inorderEnd) {
        return nullptr;
    }
    
    BinaryTree* newNode = new BinaryTree(preorder[preorderIndex--]);
    if(inorderStart == inorderEnd) {
        return newNode;
    }

    int inorderIndex = getInorderIndex(inorder,inorderStart,inorderEnd,newNode->value);
    newNode->right = constructBinaryTreeFromInorderAndPostOrderTraversal(inorder,preorder,inorderIndex+1,inorderEnd);
    newNode->left = constructBinaryTreeFromInorderAndPostOrderTraversal(inorder,preorder,inorderStart,inorderIndex-1);
    return newNode;
}

BinaryTree* maximumBinaryTree(vector<int>nums,int start,int end) {
    if(start > end) {
        return nullptr;
    }
    int index = start;
    int maxVal = nums[start];
    for(int i=start;i<=end;i++) {
        if(nums[i] > maxVal) {
            index = i;
            maxVal = nums[i];
        }
    }
    BinaryTree* newNode = new BinaryTree(maxVal);
    newNode->left = maximumBinaryTree(nums,start,index-1);
    newNode->right = maximumBinaryTree(nums,index+1,end);

    return newNode;
}

void maximumLevelSumOfABinaryTree(BinaryTree *root) {
    vector<pair<int,int>>res;
    queue<BinaryTree*>q;
    q.push(root);
    int level = 1;
    while(!q.empty()) {
        int nodeCount = q.size();
        int sum = 0;
        while(nodeCount > 0){
            auto curNode = q.front();
            sum += curNode->value;
            q.pop();

            if(curNode->left != nullptr) {
                q.push(curNode->left);
            }
            if(curNode->right != nullptr) {
                q.push(curNode->right);
            }
            nodeCount--;
        }
        res.push_back(make_pair(level,sum));
        level++;
    }
    
}

void leafNodesOfABinaryTree(BinaryTree* temp) {
    if(temp == nullptr) {
        return;
    }
    if(temp->left == nullptr && temp->right == nullptr) {
        cout<<temp->value<<" ";
    }
    leafNodesOfABinaryTree(temp->left);
    leafNodesOfABinaryTree(temp->right);
}

int maxPathSum(BinaryTree* root,int& res) {
    if(root == nullptr) {
        return 0;
    }
    cout<<"WORKING FOR: "<<root->value<<endl;
    int leftSum = maxPathSum(root->left,res);
    int rightSum = maxPathSum(root->right,res);
    leftSum = max(leftSum,0);
    rightSum = max(rightSum,0);
    int totalSum = leftSum + rightSum + root->value;
    cout<<leftSum<<" "<<rightSum<<" "<<totalSum<<endl;
    res = max(res,totalSum);
    return root->value + max(leftSum,rightSum);
}

void pseudoPalindromicPaths(BinaryTree* root,map<int,int>v,vector<map<int,int>>& paths) {
    if(root == nullptr) {
        return;
    }

    v[root->value]++;
    if(root->left == nullptr && root->right == nullptr) {
        paths.push_back(v);
    }
    pseudoPalindromicPaths(root->left,v,paths);
    pseudoPalindromicPaths(root->right,v,paths);
}

void findAPathFromRootToAGivenNode(BinaryTree* root,vector<int>v,vector<int>& path,int k) {
    if(root == nullptr) {
        return;
    }
    v.push_back(root->value);
    if(root->value == k) {
        path = v;
        return;
    }
    findAPathFromRootToAGivenNode(root->left,v,path,k);
    findAPathFromRootToAGivenNode(root->right,v,path,k);
}

void findLCA(int node1,int node2)  {
    vector<int>path1;
    vector<int>path2;
    findAPathFromRootToAGivenNode(root,{},path1,node1);
    findAPathFromRootToAGivenNode(root,{},path2,node2);
    for(auto p:path1) {
        cout<<p<<" ";
    }
    cout<<endl;
    for(auto p:path2) {
        cout<<p<<" ";
    }
    cout<<endl;
}

void validateBinaryTreeNodes(int n,vector<int>leftChild,vector<int>rightChild) {
    map<int,int>mp;
    for(int i=0;i<n;i++) {
        if(leftChild[i] != -1) {
            mp[leftChild[i]]++;
        }
        if(rightChild[i] != -1) {
            mp[rightChild[i]]++;
        }
    }

    int parentLessNode = 0;
    for(int i=0;i<n;i++) {
        if(mp.find(i)!= mp.end()) {
            if(mp[i] > 1) {
                cout<<"False"<<endl;
            }
        }
        else {
            parentLessNode++;
        }
    }
    if(parentLessNode > 1 || parentLessNode == 0) {
        cout<<"False"<<endl;
    }
    
    cout<<"true"<<endl;
}

int main() {
    root = new BinaryTree(3);
    root->left = new BinaryTree(5);
    root->right = new BinaryTree(1);
    root->left->left = new BinaryTree(6);
    root->left->right = new BinaryTree(2);
    root->right->left = new BinaryTree(0);
    root->right->right = new BinaryTree(8);
    root->left->right->left = new BinaryTree(7);
    root->left->right->right = new BinaryTree(4);
    binaryTreeLevelWiseTraversal(root);
    cout<<endl<<endl;
    vector<int>l={1,-1,3,-1};
    vector<int>r={2,-1,-1,-1};
    validateBinaryTreeNodes(4,l,r);

    return 0;
}