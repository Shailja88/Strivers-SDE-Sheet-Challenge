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
int height(TreeNode<int>* root, int &r){
    if(root==NULL)return 0;
    int lh=height(root->left,r);
    int rh=height(root->right,r);
    r=max(r,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode<int> *root){
	// Write Your Code Here.
    int r=0;
    height(root,r);
    return r;
}
