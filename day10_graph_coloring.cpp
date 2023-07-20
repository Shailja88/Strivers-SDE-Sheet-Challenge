//{  GFG Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
bool isSafe(int node,int color[],bool graph[101][101],int n,int col){
    for(int k=0;k<n;k++){
        if(color[k]==col&& graph[k][node]==1 && k!=node){
            return false;
        }
    }
    return true;
    
}

    bool solve(int node,int color[],int m,int n,bool graph[101][101]){
        if(node==n)return true;
        for(int i=1;i<=m;i++){
            if(isSafe(node,color,graph,n,i)){
                color[node]=i;
                if(solve(node+1,color,m,n,graph))return true;
                color[node]=0;
            }
        }
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n]={0};
        if(solve(0,color,m,n,graph))return true;
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends



bool isSafe(vector<vector<int>> &mat,int m,int color[],int n,int col,int node){
    for(int k=0;k<n;k++){
        if(k!=node && mat[k][node]==1 && color[k]==col)return false;
    }
    return true;
}
bool solve(vector<vector<int>> &mat,int m,int n,int color[],int node){
    if(node==n)return true;
    for(int i=1;i<=m;i++){
        if(isSafe(mat,m,color,n,i,node)){
            color[node]=i;
           if(solve(mat,m,n,color,node+1))return true;
           color[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    
    int n=mat.size();
    // if(m<n-1)return "NO";
    //n==no of nodes;
    int color[n]={0};
    if(solve(mat,m,n,color,0))return "YES";
    return "NO";

}
