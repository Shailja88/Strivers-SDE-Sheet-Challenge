#include <bits/stdc++.h> 
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
TC=O(1)
SC=O(H)
************************************************************/

class BSTiterator
{  private:
    stack<TreeNode<int>*> st;
public:
    BSTiterator(TreeNode<int> *root)
    {
        pushAll(root);
    }

    int next()
    {
        // write your code here
        TreeNode<int>* temp= st.top();
        st.pop();
       pushAll(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        // write your code here
        return (!st.empty());
    }
    void pushAll(TreeNode<int>* root){
        while(root){
         st.push(root);
         root=root->left;
        }
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
