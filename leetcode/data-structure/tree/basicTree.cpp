#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
struct TreeNode * root;

 void insertNode(int data)
 {
     queue<TreeNode *>q;
     q.push(root);

     while(!q.empty())
     {
         TreeNode * temp = q.front();
         q.pop();

         if(temp->left!=nullptr) q.push(temp->left);
         else 
         {
             temp->left=new TreeNode(data);
             return;
         }

         if(temp->right!=nullptr)q.push(temp->right);
         else 
         {
             temp->right=new TreeNode(data);
             return;
         }
         cout<<"Inserted"<<endl;
     }
 }

// leftChild - root - rightChild
void inOrderTraversal(TreeNode * temp)
{
    if(temp==nullptr)return;
    inOrderTraversal(temp->left);
    cout<<temp->val<<" ";
    inOrderTraversal(temp->right);
}

void preOrderTraversal(TreeNode *temp)
{
    if(temp==nullptr)return;
    cout<<temp->val<<" ";
    preOrderTraversal(temp->left);
    preOrderTraversal(temp->right);
}

void postOrderTraversal(TreeNode *temp)
{
    if(temp==nullptr)return;
    postOrderTraversal(temp->left);
    postOrderTraversal(temp->right);
    cout<<temp->val<<" ";
}


void levelWiseTraversal(TreeNode *head)
{
    vector<vector<int>>res;
    if(head==nullptr)return;
    
     queue<TreeNode *>q;
     
     q.push(head);

     while(q.empty()==false)
     {
         int nodeCount = q.size();
         vector<int>r;
         while(nodeCount>0)
         {
            TreeNode * temp = q.front();
            r.push_back(temp->val);
            //cout<<temp->val<<" ";
            q.pop();

            if(temp->left!=nullptr) q.push(temp->left);
            
            if(temp->right!=nullptr)q.push(temp->right);
            nodeCount--;
         }
        res.push_back(r);
         //cout<<endl;
     }

     for(auto rr:res)
     {
         for(auto r:rr)cout<<r<<" ";
         cout<<endl;
     }
}


bool isSymmetric(TreeNode* root1,TreeNode* root2)
{
    if(root1==nullptr && root2==nullptr)return true;
    if(root1 && root2 && root1->val==root2->val)
    {
        return isSymmetric(root1->left,root2->left) && isSymmetric(root1->right,root2->right);
    }
    return false;

}

int main()
{
    root =new TreeNode(5);
    insertNode(10);
    insertNode(15);
    insertNode(20);
    insertNode(25);
    insertNode(30);
    insertNode(35);

    inOrderTraversal(root);
    cout<<endl;

    preOrderTraversal(root);
    cout<<endl;

    postOrderTraversal(root);
    cout<<endl;

    levelWiseTraversal(root);
    cout<<endl;

    cout<<isSymmetric(root,root)<<endl;

    return 0;
}