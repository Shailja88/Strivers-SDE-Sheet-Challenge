/*Brute force using hashing 
TC=O(2n)
SC=O(n)......unordered_map
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr=head;
        unordered_map<Node* ,Node*>mp;
        Node* ansNode=new Node(-1);
        Node* ans=ansNode;
        while(curr){
        Node* temp=new Node(curr->val);
        mp.insert({curr,temp});
        ans->next=temp;
        ans=ans->next;
        curr=curr->next;
        }
        //hashtable random pointer ko shi jgh lagane k liye use kre ehai//
        ans=ansNode->next;
        curr=head;
        while(curr){
            Node* random=curr->random;
            Node* newrandom=mp[random];
            ans->random=newrandom;
            curr=curr->next;
            ans=ans->next;
        }
        return ansNode->next;
    }
};
/*
 * Definition for linked list.
 TC=O(3n)
 SC=O(1)
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *random;
 *		Node() : data(0), next(nullptr), random(nullptr){};
 *		Node(int x) : data(x), next(nullptr), random(nullptr) {}
 *		Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
 * };
 */
#include<bits/stdc++.h>
Node *cloneLL(Node *head){
	// Write your code here
	Node * curr=head;
	Node* front=head;
	//1. duplicates creation 
	while(curr){
		front=curr->next;
		Node* temp=new Node(curr->data);
		curr->next=temp;
		temp->next=front;
		curr=front;
	}
	///2. random pointing 
curr=head;
	while(curr){
		 Node* ran=curr->random;
		if(curr->random!=NULL)
	   curr->next->random=ran->next;
		curr=curr->next->next;
	}
	//separate new and old list 
		Node* ans=new Node(-1);
	Node* ansNode=ans;
	curr=head;
	while(curr){
	Node* temp=curr->next;
	curr->next=temp->next;
	ans->next=temp;
	ans=ans->next;
	curr=curr->next;
	}
	return ansNode->next;
}
