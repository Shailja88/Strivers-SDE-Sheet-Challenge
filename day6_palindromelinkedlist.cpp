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

#include <bits/stdc++.h> 
/****************************************************************

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
    LinkedListNode<int> *slow=head,*fast=head;
    if(head==NULL || head->next==NULL)return true;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    //odd number of list ke liye
    if(fast!=NULL){
        slow=slow->next;
    }
   ///////////middle is slow
   LinkedListNode<int> *curr=NULL;
   while(slow && slow->next){
       LinkedListNode<int> *temp=slow->next;
       slow->next=curr;
       curr=slow;
       slow=temp;
   }
if(slow->next==NULL){
    slow->next=curr;
}
//checkk kro ab 
while(slow and head){
    if(slow->data!=head->data)return false;
    slow=slow->next;
    head=head->next;
}
return true;
}
