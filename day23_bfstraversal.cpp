#include<bits/stdc++.h>
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<int>ans;
    int v=adj.size();
    vector<int>visited(v,0);
    visited[0]=1;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
     int x=q.front();
     ans.push_back(x);
     q.pop();
     for(auto in:adj[x]){
           if(visited[in]==0){
               visited[in]=1;
               q.push(in);
           }
     }

}
return ans;
}
