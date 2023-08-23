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

int heightOfBinaryTree(TreeNode<int> *root)
{
    //use the concept of level order traversal
       if(root==NULL)return 0;
       queue<TreeNode<int>*>q;
       q.push(root);
       int ans=0;
       while(1){
           int size=q.size();
           if(size==0)return ans;
           ans++;
           while(size--){
               TreeNode<int>* temp=q.front();
               q.pop();
               if(temp->left!=NULL)
               q.push(temp->left);
               if(temp->right!=NULL)
               q.push(temp->right);
           }

 }
 return ans;
}
////
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
//recursive nature left ka max nikalo right ka max nikalo aur 1 add kr do
int heightOfBinaryTree(TreeNode<int> *root)
{
    if(root==NULL)return 0;
return max(heightOfBinaryTree(root->left),heightOfBinaryTree(root->right))+1;
	// Write your code here.
}
