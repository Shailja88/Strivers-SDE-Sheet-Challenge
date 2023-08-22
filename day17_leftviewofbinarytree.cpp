//method 1
#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here


    vector<int>ans;
    if(root==NULL)return ans;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
     int flag=0;
     int size=q.size();
     while(size--){
        TreeNode<int>* temp=q.front();
        q.pop();
        if(flag==0){
        ans.push_back(temp->data);
        flag=1;
        }
       if(temp->left!=NULL)
       q.push(temp->left);
       if(temp->right!=NULL)
       q.push(temp->right);

         }
}return ans;
}

///method 2
#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void left(vector<int>&ans,int level,TreeNode<int> *root){
    if(root==NULL)return;
    if(level==ans.size())
    ans.push_back(root->data);
    left(ans,level+1,root->left);
  left(ans,level+1,root->right);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int>ans;
    left(ans,0,root);
    return ans;
}
