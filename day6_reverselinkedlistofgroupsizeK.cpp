/**
leetcode
TC=O(N)
SC=O(1)
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int cnt=0;
        while(temp){
         cnt++;
         temp=temp->next;
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy,*curr=dummy,*nex=dummy;
        while(cnt>=k){
            curr=prev->next;
            nex=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
            }
            prev=curr;
            cnt=cnt-k;
        }
        
        return dummy->next;
           }
};

/*codestudio*/
#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	if(head==NULL)return head;
	Node* dummy=new Node(0);
	dummy->next=head;
	Node* curr=dummy,*nex=dummy,*prev=dummy;
	for(int i=0;i<n;i++){
		if(prev==NULL || prev->next==NULL){
			break;
		}
		if(b[i]==0)continue;
		curr=prev->next;
		nex=curr->next;
		for(int j=1;j<b[i]&& curr!=NULL && curr->next!=NULL;j++){
			curr->next=nex->next;
			nex->next=prev->next;
			prev->next=nex;
			nex=curr->next;
		}
		prev=curr;
	}
	return dummy->next;
}
