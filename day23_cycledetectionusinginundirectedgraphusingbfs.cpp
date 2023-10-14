//using bfs
#include<bits/stdc++.h>
using namespace std;
bool bfs(int s,vector<bool>&visi,vector<vector<int>>&adj){
    visi[s]=true;
    unordered_map<int,int>parent;
    parent[s]=-1;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int r=q.front();
        q.pop();
      for(auto in:adj[r]){
           if(!visi[in]){
               visi[in]=true;
               parent[in]=r;
               q.push(in);
           }
           else if(parent[r]!=in)return true;
      }
        
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<bool>visi(n+1,false);
    // Write your code here.
    //create adjacency list
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    
    
    //created adjacency list
    for(int i=0;i<n;i++){
        if(!visi[i]){
            int ans=bfs(i,visi,adj);
            if(ans)return "Yes";
        }
    }
    return "No";
}

