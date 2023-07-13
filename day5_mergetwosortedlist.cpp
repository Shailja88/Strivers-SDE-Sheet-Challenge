#include <bits/stdc++.h>

/************************************************************
Iterative method
    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Iterative method
    Node<int>* ans=new Node(0);
    Node<int>* ansfinal=ans;
    while(first && second){
        if(first->data>=second->data){
            ans->next=second;
            second=second->next;
        }
        else{
            ans->next=first;
            first=first->next;
        }
        ans=ans->next;
    }
    if(first)ans->next=first;
    if(second)ans->next=second;
    return ansfinal->next;
}


#include <bits/stdc++.h>

/************************************************************
RECURSIVE METHOD
    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first==NULL)return second;
    else if(second==NULL)return first;
    else if(first->data>=second->data){
        second->next=sortTwoLists( first,second->next);
        return second;
    }
    else{
        first->next=sortTwoLists( first->next,second);
        return first;
    }
}

