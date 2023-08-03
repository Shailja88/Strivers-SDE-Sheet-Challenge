#include<bits/stdc++.h>
struct Node{
  
  int cnt,value,key;
  Node* next;
  Node* prev;
  Node(int _value,int _key){
      value=_value;
      key=_key;
      cnt=1;
  }
};
struct List{
 
    int size;
    Node* head;
    Node* tail;
    List(){

        size=0;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    void addFront(Node * node){
    Node* temp=head->next;
    node->next=temp;
    node->prev=head;
    head->next=node;
    temp->prev=node;
    size++;
}
void deletee(Node* node){
    Node* prevNode=node->prev;
    Node* nextNode=node->next;
    prevNode->next=nextNode;
    nextNode->prev=prevNode;
    size--;
}
};

class LFUCache
{ 
    map<int,Node*>keyNode;
    map<int,List*>ListFreqMap;
    int cursize;
    int maxsizecache;
    int minfreq;
public:


    LFUCache(int capacity)
    {
        // Write your code here.
        maxsizecache=capacity;
        minfreq=0;
        cursize=0;
    }
    void updateFreListMap(Node * node){
          keyNode.erase(node->key);//sbse phle keynode s erase kr diya 
          //ab freqnodlist s bhi erse kro 
            ListFreqMap[node->cnt]->deletee(node);
           if(node->cnt==minfreq && ListFreqMap[node->cnt]->size==0){
               minfreq++;
           }
     List* nexthigherfreqlist=new List();
      if(ListFreqMap.find(node->cnt+1)!=ListFreqMap.end()){//if there exists next frequency already
          nexthigherfreqlist=ListFreqMap[node->cnt+1];

      }
      node->cnt+=1;
      nexthigherfreqlist->addFront(node);
      ListFreqMap[node->cnt]=nexthigherfreqlist;
      keyNode[node->key]=node;

   }

    int get(int key)
    {
        // Write your code here.
        if(keyNode.find(key)!=keyNode.end()){
            Node * temp=keyNode[key];//node 
            int ans=temp->value;
              updateFreListMap(temp);
          return ans;
      }
        return -1;//if key not present is keynode;
    }

    void put(int key, int val)
    {
        // Write your code here.
        if(maxsizecache==0)return;
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            node->value=val;
            updateFreListMap(node);
        }
        else{
            if(cursize==maxsizecache){
                List* list=ListFreqMap[minfreq];
                keyNode.erase(list->tail->prev->key);
                ListFreqMap[minfreq]->deletee(list->tail->prev);
                cursize--;
            }
            cursize++;
            minfreq=1;
            List* listFreq=new List();
            if(ListFreqMap.find(minfreq)!=ListFreqMap.end()){
              listFreq=ListFreqMap[minfreq];  
            }
            Node* node=new Node(val,key);
            listFreq->addFront(node);
            keyNode[key]=node;
            ListFreqMap[minfreq]=listFreq;
        }
    }
};
