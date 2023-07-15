/*
revisit k time dhyan do
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* mergeLL(Node* left, Node* right){
    if(left == NULL){
        return right;
    }

    if(right == NULL){
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->child = left;
            temp = left;
            left = left->child;
        }else{
            temp->child = right;
            temp = right;
            right = right->child;
        }
    }

    if(left){
		temp->child = left;
	}else{
		temp->child = right;
	}

    ans = ans->child;
    return ans;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head->next == NULL){
		return head;
	}

	Node* left = head;

	Node* sorted = flattenLinkedList(head -> next);

	left->next = NULL;

	Node* ans = mergeLL(left, sorted);

	return ans;
}
