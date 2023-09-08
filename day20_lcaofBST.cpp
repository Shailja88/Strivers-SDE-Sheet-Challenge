//METHOD 1 tc=o(n)
/************************************************************
    Following is the Binary Search Tree node structure

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

************************************************************/
bool cal(TreeNode* root, vector<TreeNode*>&path,TreeNode*x){
if(root==NULL)return false;
path.push_back(root);
 if(root==x)return true;
if(cal(root->left,path,x)||cal(root->right,path,x))return true;
path.pop_back();
return false;
}
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    //do path find kro find kro jo sbse last m match kr rha hai upr s usko return kro 
    vector<TreeNode*>path1;
    vector<TreeNode*>path2;
    TreeNode* ans=NULL;
    cal(root,path1,P);
    cal(root,path2,Q);
    for(int i=0;i<path1.size()&& i<path2.size();i++){
        if(path1[i]==path2[i]){
            ans=path1[i];
        }
    }
    return ans;
}


//method2
/************************************************************
    Following is the Binary Search Tree node structure

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

************************************************************/

TreeNode *LCAinaBST(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // Write your code here.
    if(root==NULL)return NULL;
    int curr=root->data;
    if(curr<p->data && curr<q->data){
        return LCAinaBST(root->right,p,q);
    }
    if(curr>p->data && curr>q->data)
    return LCAinaBST(root->left,p,q);
    return root;
}



