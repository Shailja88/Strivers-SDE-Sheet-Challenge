/**
TC=O(N)
SC=O(N)
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
         TreeNode* temp=q.front();
         q.pop();
         if(temp==NULL)s.append("#,");
         else {
       s.append(to_string(temp->val));
       s.append(",");
         }
         
        
        if(temp!=NULL){
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    
    return s;
    }
    // Decodes your encoded data to tree.1,2,3,4,#,#,#,4......
    TreeNode* deserialize(string data) {
    if(data.size()==0)return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode* root=new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        getline(s,str,',');
        //root->left 
      if(str=="#")
      temp->left=NULL;
      else{
     TreeNode* l=new TreeNode(stoi(str));
     temp->left=l;
     q.push(l);

      }
      getline(s,str,',');
      if(str=="#")
      temp->right=NULL;
      else{
          TreeNode* r=new TreeNode(stoi(str));
          temp->right=r;
          q.push(r);
      }


        //root->right

    }
    return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
