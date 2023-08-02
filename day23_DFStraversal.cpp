#include<bits/stdc++.h>
void dfsrec(vector<int>adj[],int n,vector<int>&visi,int s,vector<int>&temp){
    visi[s]=1;
    temp.push_back(s);
    for(auto in:adj[s]){
        if(visi[in]==0){
         dfsrec(adj,n,visi,in,temp);
            }
    }
}
vector<vector<int>>dfs(vector<int>adj[],int n){
    vector<vector<int>>ans;
     vector<int>visi(n,0);
     for(int i=0;i<n;i++){
         if(visi[i]==0){
             vector<int>temp;
             dfsrec(adj,n,visi,i,temp);
              ans.push_back(temp);
         }
     }
     return ans;
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //V VERTEX 
    ////make adjacency matrix first

       vector<int>adj[V];
       for(int i=0;i<E;i++){
           adj[edges[i][0]].push_back(edges[i][1]);
           adj[edges[i][1]].push_back(edges[i][0]);
       }
       return dfs(adj,V);
}
