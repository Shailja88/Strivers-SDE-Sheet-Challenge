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
TreeNode<int> *helper(vector<int> &inorder,int instart,int inend, vector<int> &preorder,int prestart,int prend,map<int,int>&mp){
   if(instart>inend || prestart>prend)return NULL;
     //create a root;
     TreeNode<int>* root=new TreeNode<int>(preorder[prestart]);
     int ele=mp[root->data];
     int nEle=ele-instart;
     root->left= helper(inorder,instart,ele-1,preorder,prestart+1,prestart+nEle,mp);
     root->right= helper(inorder,ele+1,inend,preorder,prestart+nEle+1,prend,mp);
return root;




}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int instart=0,inend=inorder.size()-1;
    int prestart=0,prend=preorder.size()-1;
    map<int,int>mp;
    for(int i=0;i<=inend;i++){
        mp[inorder[i]]=i;
    }
   return helper(inorder,instart,inend,preorder,prestart,prend,mp);
}
