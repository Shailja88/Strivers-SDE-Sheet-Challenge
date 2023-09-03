/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
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
   };
   
   TC=O(nlogn)
   SC=O(n)
 ************************************************************/
 #include<bits/stdc++.h>
TreeNode<int>* helper(vector<int>&postOrder,int ps,int pe,vector<int>&inOrder,int is,int ie,map<int,int>&mp){
if(is>ie||ps>pe)return NULL;
//create a node

TreeNode<int>* root=new TreeNode<int>(postOrder[pe]);
int ele=mp[root->data];
int nEle=ele-is;
root->left=helper(postOrder,ps,ps+nEle-1,inOrder,is,ele-1,mp);
root->right=helper(postOrder,ps+nEle,pe-1,inOrder,ele+1,ie,mp);
return root;


}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder){
	// Write your code here.
     int is=0,ie=inOrder.size()-1;
     int ps=0,pe=postOrder.size()-1;
     map<int,int>mp;
     for(int i=0;i<=ie;i++){
          mp[inOrder[i]]=i;
     }
     return helper(postOrder,ps,pe,inOrder,is,ie,mp);
}
