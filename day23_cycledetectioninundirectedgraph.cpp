///using dfs
#include<bits/stdc++.h>
using namespace std;
bool dfs(int s,vector<bool>&visi,vector<vector<int>>adj,int pare){
    visi[s]=true;
    for(auto in:adj[s]){
        if(!visi[in]){
            if(dfs(in,visi,adj,s))return true;
        }
        else if(in!=pare)return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>>adj(n+1);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>visi(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visi[i]){
            if(dfs(i,visi,adj,0))return "Yes";
        }
    }
    return "No";
    
}
