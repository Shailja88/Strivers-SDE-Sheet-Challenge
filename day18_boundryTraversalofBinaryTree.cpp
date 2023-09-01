/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>*root){
    return !root->left && !root->right;
}
void leftt(TreeNode<int> *root,vector<int>&res){
    //temp m root store kro aur usi ka use kro
    TreeNode<int> *temp=root;
    while(temp)
 {   //check kro khi leaf node to n hi hai
    if(!isLeaf(temp))res.push_back(temp->data);
    if(temp->left)temp=temp->left;
    else temp=temp->right;
    }
}
void rightt(TreeNode<int> *root,vector<int>&res){
        TreeNode<int> *temp=root;
        vector<int>t;
        while(temp)
      {  if(!isLeaf(temp))t.push_back(temp->data);
        if(temp->right)temp=temp->right;
        else
        temp=temp->left;}
        for(int i=t.size()-1;i>=0;i--){
            res.push_back(t[i]);
        }
}
void leaff(TreeNode<int> *root,vector<int>&res){
        TreeNode<int> *temp=root;
       //preorder ka use krna hai
       if(isLeaf(temp))res.push_back(temp->data);
       if(temp->left)leaff(temp->left,res);
       if(temp->right)leaff(temp->right,res);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{

    vector<int>res;
    if(!root)return res;
    res.push_back(root->data);
    if(root->left)leftt(root->left,res);
    leaff(root,res);
    if(root->right) rightt(root->right,res);
    return res;
}
