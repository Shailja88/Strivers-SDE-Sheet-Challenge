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
 void inorder(TreeNode* root,vector<int>&v){
    if(root==NULL){

 return;
    }
        
     inorder(root->left,v);
     v.push_back(root->data);
     inorder(root->right,v);
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{ 
    vector<int>ans;
        int pre=-1,suc=-1;
    inorder(root,ans);
     for(int i=0;i<ans.size();i++)

    {
      if(ans[i]<key)
      pre=ans[i];

    }

    for(int i=ans.size()-1;i>=0;i--)

    {
      if(ans[i]>key)
      suc=ans[i];
   }

    return {pre,suc};
}



///
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

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.

int pre=-1;
int suc=-1;
    //optimal approach
    TreeNode*root1=root;
    TreeNode* root2=root;
    
  while(root1!=NULL){
   if(root1->data<=key){
       root1=root1->right;
   }
   else{
       suc=root1->data;
       root1=root1->left;
  }}
while(root2!=NULL){
  if(root2->data>=key){
      root2=root2->left;
  }
  else{
      pre=root2->data;
      root2=root2->right;
    
}  
}    
    return {pre,suc};
}
