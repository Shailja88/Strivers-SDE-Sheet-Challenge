//tc=o(2e+v)
//sc=o(2e)
#include<bits/stdc++.h>
using namespace std;
bool dfs(int start,vector<int>&col,vector<int>adj[],int n){
	col[start]=n;
	for(auto in:adj[start]){
		if(col[in]==-1){
          if(!dfs(in,col,adj,!n))return false;
         	}
		 else if(col[in]==col[start])return false;
	}
	return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.

	int n=edges.size();
	int m=edges[0].size();
	vector<int>adj[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(edges[i][j]==1)
			adj[i].push_back(j);
		}
	}
	vector<int>color(n,-1);
	for(int i=0;i<n;i++){
		if(color[i]==-1){
			if(!dfs(i,color,adj,0))return false;
		}
	}
	return true;
}
