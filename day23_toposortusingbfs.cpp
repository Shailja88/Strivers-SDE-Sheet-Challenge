#include <bits/stdc++.h> 
using namespace std;
//using bfs 
//tc=O(v+e)
//sc=o(v)
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    //make adj list
    vector<vector<int>>adj(v);
    //make adjacency list
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    //find indegrees
    vector<int>indegre(v,0);
    for(int i=0;i<adj.size();i++){
        for(auto x: adj[i]){
            indegre[x]++;
        }
    }
    queue<int>q;
    //jiski indegree 0 ho usko queue m dalo
    for(int i=0;i<v;i++)
    {
        if(indegre[i]==0)
        q.push(i);
    }
    //apply bfs
    vector<int>ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto in:adj[front]){
                indegre[in]--;
                if(indegre[in]==0){
                    q.push(in);
                }
 }

    }
    return ans;
}
