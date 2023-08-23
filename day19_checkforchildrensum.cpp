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
