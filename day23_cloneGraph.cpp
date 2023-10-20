//using dfs
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
unordered_map<Node*,Node*>mp;
    void DFS(Node* node,Node* clone_node){
        for(Node* n:node->neighbors){
           if(mp.find(n)==mp.end()){
            ///abhi tk visit nhi kiy mtlb clone node nhi bni hai
                Node* clone=new Node(n->val);
                mp[n]=clone;
                clone_node->neighbors.push_back(clone);
                DFS(n,clone);
           }
        else{
            clone_node->neighbors.push_back(mp[n]);
        }

        }
    }
    Node* cloneGraph(Node* node) {
      if(!node)return NULL;

      mp.clear();
      ///clone the given node
      Node* clone_node=new Node(node->val);
      //clone it's neighbors and recusively their neighbors
      /*
      but if a node reappears , access that clone node
      store them in a map
      */



      mp[node]=clone_node;
      DFS(node,clone_node);
      return clone_node;
    }
};




//using bfs
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
   unordered_map<Node*,Node*>mp;
//    void DFS(Node* node,Node* clone_node){
//        for(Node* n:node->neighbors){
//            if(mp.find(n)==mp.end()){
//                Node* clone=new Node(n->val);
//                mp[n]=clone;
//                clone_node->neighbors.push_back(clone);
//                DFS(n,clone);
//            }
//            else {
//                clone_node->neighbors.push_back(mp[n]);
//            }
//        }
//    }
   void BFS(queue<Node*>&que){
       while(!que.empty()){
           Node* node=que.front();
           Node* clone_node=mp[node];
           que.pop();
              for(Node* n:node->neighbors){
           if(mp.find(n)==mp.end()){
               Node* clone=new Node(n->val);
               mp[n]=clone;
               clone_node->neighbors.push_back(clone);
              que.push(n);
           }
           else {
               clone_node->neighbors.push_back(mp[n]);
           }
       }
       }
   }
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        mp.clear();
        Node* clone_node=new Node(node->val);
        mp[node]=clone_node;
      queue<Node*>que;
      que.push(node);
      BFS(que);
        return clone_node;
    }
};


///using bfs
