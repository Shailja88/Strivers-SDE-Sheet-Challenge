#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int>ans;
    if(root==NULL)return ans;
    queue<BinaryTreeNode<int> *>q;
    int flag=0;
    q.push(root);
    while(!q.empty()){
          int size=q.size();
          vector<int>temp;
          while(size--){
           BinaryTreeNode<int> * t=q.front();
            q.pop();
           temp.push_back(t->data);
               if(t->left!=NULL)
               q.push(t->left);
               if(t->right!=NULL)
               q.push(t->right);
          }
        if(flag%2==0){
        for(auto in:temp){
        ans.push_back(in);
          }
        }
          else if(flag%2!=0){
            reverse(temp.begin(),temp.end());
            for(auto in:temp)
            ans.push_back(in);
        }
         flag++;

    }
    
return ans;
}
