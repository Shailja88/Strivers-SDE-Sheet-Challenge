/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };
EASYYYY 
******************************************************/

bool helper(BinaryTreeNode<int>* n1 ,BinaryTreeNode<int>* n2){
    
 if(!n1 && !n2 )return true;
 else if(!n1||!n2)return false;
 else {
     //dono hai 
     return (n1->data==n2->data && helper(n1->left ,n2->right)&& helper(n1->right ,n2->left));
     
 }
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
       if(!root)return true;
      return helper(root->left ,root->right);
}
