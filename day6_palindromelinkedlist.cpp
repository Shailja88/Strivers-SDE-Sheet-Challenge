#include <bits/stdc++.h> 
/****************************************************************
 BRUTE FORCE 
 TC=O(2N);
 SC=O(N)
    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
  // Write your code here.
    if(head==NULL || head->next==NULL)return true;
    vector<int>v;
    while(head!=NULL){
        v.push_back(head->data);
        head=head->next;
    }
   int size=v.size();
   size=size/2;
   for(int i=0;i<size;i++){
      if(v[i]!=v.back())return false;
      else
      v.pop_back();
   }
return true;
}
