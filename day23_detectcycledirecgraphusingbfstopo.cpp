
       #include<bits/stdc++.h>
using namespace std;
//tc=o(n+e)
//sc=o(n+e)

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  //using bfs //topological sort
     //make adj matrix
     int cnt=0;
     queue<int>q;
     vector<bool>visi(n+1,false);
     vector<int>indegree(n+1 ,0);
     vector<vector<int>>adj(n+1);
     for(int i=0;i<edges.size();i++){
       int u=edges[i].first;
       int v=edges[i].second;
       adj[u].push_back(v);
     }
    for(int i=0;i<adj.size();i++){
      for(auto j:adj[i]){
        indegree[j]++;
      }
    } 
    for(int i=1;i<=n;i++){
      if(indegree[i]==0)
      q.push(i);
    }
     ///do bfs
     
          while(!q.empty()){
         int front=q.front();
         q.pop();
         cnt++;
         for(auto in:adj[front]){
           indegree[in]--;
           if(indegree[in]==0)
           q.push(in);
         }
         
       }
     
    if(cnt==n)return 0;
    return 1;

     
}


//course schedule 




