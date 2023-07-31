#include<bits/stdc++.h>
class LRUCache
{

public:
class Node{
public:
int key;
int value;
Node* next;
Node* prev;
Node(int k,int v){
    key=k;
    value=v;
}

};
  Node * head=new Node(-1,-1);
  Node* tail=new Node(-1,-1);
  int cap;
  unordered_map<int,Node*>mp;
    LRUCache(int capacity)
    {
        // Write your code here
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
   void addnode(Node* newnode){
      Node * temp=head->next;
      newnode->next=temp;
      newnode->prev=head;
      head->next=newnode;
      temp->prev=newnode;
   }
 void deletenode(Node* delnode){
     Node* delprev=delnode->prev;
     Node* delnext=delnode->next;
     delprev->next=delnext;
     delnext->prev=delprev;
 }
    int get(int key)
    {
        // Write your code here
        if(mp.find(key)!=mp.end()){
         Node* resnode=mp[key];
         int ans=resnode->value;
         mp.erase(key);
         deletenode(resnode);
         addnode(resnode);
         mp[key]=head->next;
         return ans;
        }
        return -1;
    }


    void put(int key, int value)
    {
        // Write your code 
        //agar phle s present hai key to 
        if(mp.find(key)!=mp.end()){
            Node* existingnode=mp[key];
            mp.erase(key);
            deletenode(existingnode);
        }
        //agar capacity full hai to 
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
          deletenode(tail->prev);
        }
        //add kro head->next m sath m insert kr do key ko map me 
        addnode(new Node(key,value));
        mp[key]=head->next;
    }
};
