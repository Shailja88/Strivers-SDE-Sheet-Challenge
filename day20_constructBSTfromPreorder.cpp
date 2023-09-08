//brute force tc=o(n^2)
/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*************************************************************/
TreeNode* insert(TreeNode* root,int val){
      if(root==NULL){
          return new TreeNode(val);
      }
     else if(root->data>val){
          root->left=insert(root->left,val);
      }
      else if(root->data<val){
          root->right=insert(root->right,val);
      }
      return root;
}
TreeNode *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    TreeNode* root=NULL;
    for(int val:preOrder){
       root= insert(root,val);
    }
    return root;
}

//method 2
/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
    //method 2
*************************************************************/
TreeNode* solution(vector<int>&inorder,int is,int ie,vector<int>&preOrder,int ps,int pe,map<int,int>&mp){
if(is>ie||ps>pe)return NULL;
TreeNode* root=new TreeNode(preOrder[ps]);
int ele=mp[root->data];
int nEle=ele-is;
root->left=solution(inorder,is,ele-1,preOrder,ps+1,ps+nEle,mp);
root->right=solution(inorder,ele+1,ie,preOrder,nEle+ps+1,pe,mp);
return root;
}
TreeNode *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
 
    vector<int>inorder=preOrder;
    sort(inorder.begin(),inorder.end());
    int is=0,ie=inorder.size()-1,ps=0,pe=preOrder.size()-1;
    map<int,int>mp;
   for(int i=0;i<inorder.size();i++){
       mp[inorder[i]]=i;
   }
    return solution(inorder,is,ie,preOrder,ps,pe,mp);
    
}


//method 3
/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
    tc=O(3n)
    sc=O(n)//stack space;
*************************************************************/
TreeNode* build(vector<int> &preOrder,int &i,int ub){
    if(i==preOrder.size() || preOrder[i]>ub)return NULL;
    TreeNode* root=new TreeNode(preOrder[i++]);
    root->left=build(preOrder,i,root->data);
    root->right=build(preOrder,i,ub);
    return root;
}
TreeNode *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
 int i=0;
 return build(preOrder,i,INT_MAX);
}
