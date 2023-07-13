/*
Following is the class structure of the Node class:
Brute force
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
*/

Node* removeKthNode(Node* head, int K)
{
    // brute force
    //count the totall number of nodes
    int cnt=0;
    Node* h=head;
    while(h){
   cnt++;
    h=h->next;
    }
    
    int front=cnt-K;
    if(front==0)return head->next;
     Node* temp=head;
     while(--front){
         temp=temp->next;
     }
temp->next=temp->next->next;
return head;
}
/*Best*/
/*
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
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    Node* slow=head;
    Node* fast=head;
    while(K--){
        fast=fast->next;
        
    }
    if(fast==NULL)return head->next;
    while(fast->next && fast){
        slow=slow->next;
        fast=fast->next;
        
    }
    slow->next=slow->next->next;
    return head;
}


