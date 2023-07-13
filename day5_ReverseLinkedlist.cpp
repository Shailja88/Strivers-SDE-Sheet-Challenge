/*
Best approach
codestudio
TC=O(n)
SC=O(1)
*/
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *ans=NULL;
    while(head!=NULL){
        LinkedListNode<int> *temp=head->next;
        head->next=ans;
        ans=head;
        head=temp;
    }
    
    return ans;
    
}
/*LEETCODE
*/
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* result=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=result;
            result=curr;
            curr=temp;
        }
        return result;
    }
};
/*SC=O(N)
  TC=O(N)
  */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int>v;
        for(ListNode* curr=head;curr!=NULL;curr=curr->next){
           v.push_back(curr->val);
        }
        for(ListNode* curr=head;curr!=NULL;curr=curr->next){
            curr->val=v.back();
            v.pop_back();

        }
        return head;
    }
};
