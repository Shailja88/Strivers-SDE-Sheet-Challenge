#include <bits/stdc++.h> 
void dfs(vector<bool>&visi,int s,vector<vector<int>>&adj,stack<int>&st){
    visi[s]=true;
   for(auto in:adj[s]){
       if(!visi[in]){
           dfs(visi,in,adj,st);
       }
   } 

    st.push(s);           
    
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    //make adj matrix
    stack<int>st;
    vector<bool>visi(v,false);
vector<int>ans;
    vector<vector<int>>adj(v);
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    for(int i=0;i<v;i++){
        if(!visi[i]){
            dfs(visi,i,adj,st);
        }
    }

   while(!st.empty()){
       int r=st.top();
       ans.push_back(r);
       st.pop();
   }
  
  return ans;  
}
