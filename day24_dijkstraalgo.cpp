/*TC=O(elogv)
  SC=O(v+e)
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<pair<int,int>>adj[vertices];
    for(auto in:vec){
        adj[in[0]].push_back({in[1],in[2]});
        adj[in[1]].push_back({in[0],in[2]});
    }
    //adj list taiyar

    vector<int>dist(vertices,INT_MAX),parent(vertices);
    
    dist[source]=0;
    //dist and parent taiyar ho gya
    //priority queue bna lo
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,source});//{dis,node};
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int dis=it.first;//cost
        int node=it.second;

        for(auto in:adj[node]){
            int adjnode=in.first;
            int ecost=in.second;
            if(dis+ecost<dist[adjnode]){
                dist[adjnode]=dis+ecost;
                pq.push({dis+ecost,adjnode});
                parent[adjnode]=node;
            }
        }
    }

  
   return dist;
}
