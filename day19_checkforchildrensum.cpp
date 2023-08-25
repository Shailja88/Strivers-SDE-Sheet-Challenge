/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

bool isParentSum(Node *root){
    // Write your code here.
    if(root==NULL || (root->left==NULL && root->right==NULL))return 1;
     int l=0;
     int r=0;
     if(root->left!=NULL)
     l=root->left->data;
     if(root->right!=NULL)
     r=root->right->data;
     if(l+r== root->data
     && isParentSum(root->left)
     && isParentSum(root->right)){
         return true;

     }
     else 
     return false;
}

/////change children node sum
#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
 void increment(BinaryTreeNode < int > * node,int diff){
 if(node->left!=NULL){
   node->left->data+=diff;
   increment(node->left,diff);
 }
 else if(node->right!=NULL){
   node->right->data+=diff;
   increment(node->right,diff); 
 }



 }
void changeTree(BinaryTreeNode < int > * node) {
    // Write your code here.
    ///TC=O(n^2);
    int left_data=0,right_data=0,diff;
    ///base case
    if(node==NULL||(node->left==NULL && node->right==NULL))return;
    //recursive code
    changeTree(node->left);
    changeTree(node->right);

//CALCULATION PART
    if(node->left!=NULL)
    left_data=node->left->data;
    if(node->right!=NULL)
    right_data=node->right->data;
     
   diff=left_data+right_data-node->data;

   if(diff>0)
   node->data+=diff;
   else if(diff<0){
       increment(node,-diff);
   }
}  


#include <bits/stdc++.h> 
/*************************************************************
TC=O(N)
SC=O(H) 
    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root==NULL)return;
    int child=0;
    if(root->left){
        child+=root->left->data;
    }
    if(root->right){
        child+=root->right->data;
    }
    if(child>=root->data)root->data=child;
    else{
        if(root->left)root->left->data=root->data;
        else if(root->right)root->right->data=root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int tot=0;
    if(root->left)tot+=root->left->data;
    if(root->right)tot+=root->right->data;
    if(root->left || root->right)root->data=tot;
}  
