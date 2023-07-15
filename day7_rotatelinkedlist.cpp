/**
TC=O(n)
SC=O(1)
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(head==NULL ||head->next==NULL)return head;
      int cnt=0;
     Node* temp=head;
     while(temp){
     temp=temp->next;
     cnt++;
   }
     k=k%cnt;
     if(k==0)return head;
  int x=cnt-k;
  Node* t=head;
  while(--x){
   t=t->next;
  }
  Node* store=t->next;
  t->next=NULL;
  Node* ans=store;
  while(store->next!=NULL){
       store=store->next;
  }
  store->next=head;
  return ans;
}
