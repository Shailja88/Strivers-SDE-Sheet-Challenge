/********************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        int data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
********************************************************************/
void dfs(BinaryTreeNode<int> * root,vector<string>&ans,string t){
    if(!root)
    {  
        return;
    }
    t=t+(to_string(root->data))+" ";
    if(!root->left && !root->right)
    {
      ans.push_back(t);
    }
    else

   { 
    dfs(root->left,ans,t);
    dfs(root->right,ans,t);
    }
     t.pop_back();
}
vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    // Write your code here.
    vector<string>ans;
    if(!root)return ans;
    string s;
    dfs(root,ans,s);
    return ans;
}
