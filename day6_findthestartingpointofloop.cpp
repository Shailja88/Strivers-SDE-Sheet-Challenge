/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* curr=head;
        unordered_set<ListNode*> st;
        while(curr){
        if(st.find(curr)!=st.end())
        return curr;
        else {
        st.insert(curr);
        curr=curr->next;
        }
    }
    return NULL; }

};
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

best
*****************************************************************/

Node *firstNode(Node *head)
{
    //    Write your code here.
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next ){
      slow=slow->next;
      fast=fast->next->next;
      if(slow==fast){
          fast=head;
          while(slow!=fast){
              slow=slow->next;
              fast=fast->next;
          }
          return slow;
      }
    }
    return NULL;
}
