/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    int carry=0;
    Node* ansfinal=new Node(0);
    Node* ans=ansfinal;
    while(num1!=NULL || num2!=NULL){
        int x=(num1!=NULL)?num1->data:0;
        int y=(num2!=NULL)?num2->data:0;
        int sum=x+y+carry;
        carry=sum/10;
        ans->next=new Node(sum%10);
        if(num1 !=NULL)num1=num1->next;
        if(num2!=NULL)num2=num2->next;
        ans=ans->next;
    }
    if(carry){
        ans->next=new Node(carry);
    }
return ansfinal->next;
}
