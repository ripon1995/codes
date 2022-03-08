#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insertion(TreeNode *root, int val)
{
    if(root==nullptr)
    {
        root = new TreeNode(val);
    }
    if(val>root->val)
    {
        root->right=insertion(root->right,val);
    }
    if(val < root->val)
    {
        root->left=insertion(root->left,val);
    }

    return root;
}


// leftChild - root - rightChild
void inOrderTraversal(TreeNode * temp)
{
    if(temp==nullptr)return;
    inOrderTraversal(temp->left);
    cout<<temp->val<<" ";
    inOrderTraversal(temp->right);
}

bool isValidBinaryTree(TreeNode *root)
{
    if(root==nullptr)return true;
    if(root->left!=nullptr && root->left->val>root->val)return false;
    if(root->right!=nullptr && root->right->val<root->val)return false;
    if(isValidBinaryTree(root->left)==false || isValidBinaryTree(root->right)==false)
    {
        return false;
    }
    return true;
}
int maxValue(TreeNode *temp,int maxVal)
{
    if(temp==nullptr)return maxVal;
    if(temp->val>maxVal)maxVal=temp->val;
    int leftMax=maxValue(temp->left,maxVal);
    int rightMax=maxValue(temp->right,maxVal);
    return max(leftMax,rightMax);
}

int minValue(TreeNode *temp,int minVal)
{
    if(temp==nullptr)return minVal;
    if(temp->val<minVal)minVal=temp->val;
    int leftMin=minValue(temp->left,minVal);
    int rightMin=minValue(temp->right,minVal);
    return min(leftMin,rightMin);
}
bool searchInBinarySearchTree(TreeNode * root,int data)
{
    if(root==nullptr)return false;
    if(root->val==data)return true;
    if(data>root->val) return searchInBinarySearchTree(root->right,data);
    if(data<root->val) return searchInBinarySearchTree(root->left,data);
    return false;
}
bool findTarget(TreeNode* root, int k) 
{   vector<int>data;
    queue<TreeNode *>q;
    q.push(root);
    while(q.size()>0)
    {
        TreeNode * temp=q.front();
        q.pop();
        if((k-temp->val!=temp->val) && searchInBinarySearchTree(root,k-temp->val)==true)return true;
        if(temp->left!=nullptr)q.push(temp->left);
        if(temp->right!=nullptr)q.push(temp->right);
    }
    return false;
}

TreeNode * lca(TreeNode * root,int n1,int n2)
{
    if(root==nullptr)return nullptr;
    if(root->val>n1 && root->val>n2)return lca(root->left,n1,n2);
    if(root->val<n1 && root->val<n2)return lca(root->right,n1,n2);
    return root;
}
    
int main()
{
    TreeNode *root = new TreeNode(5);
    insertion(root,3);
    insertion(root,8);
    insertion(root,2);
    insertion(root,4);
    insertion(root,6);
    insertion(root,9);

    inOrderTraversal(root);
    cout<<endl;
    cout<<lca(root,2,3)->val<<endl;
    return 0;
}