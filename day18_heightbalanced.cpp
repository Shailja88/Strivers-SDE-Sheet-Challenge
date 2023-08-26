/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int check(TreeNode<int>* root){
    if(root==NULL)return 0;
   int l= check(root->left);
   if(l==-1)return -1;
   int r= check(root->right);
   if(r==-1)return -1;
   if(abs(l-r)>1)return -1;
    return 1+max(l,r);
}
bool isBalancedBT(TreeNode<int>* root){
    // Write your code here.
    return check(root)!=-1;
}
