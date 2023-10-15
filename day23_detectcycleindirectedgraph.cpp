///using dfs
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<bool>& visi, vector<bool>& dfsvisi, int s, vector<vector<int>>& adj) {
    visi[s] = true;
    dfsvisi[s] = true;
    for (auto in : adj[s]) {
        if (!visi[in]) {
            if (dfs(visi, dfsvisi, in, adj))
                return true;
        } else if (dfsvisi[in]) {
            return true;
        }
    }

    dfsvisi[s] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    // Construct the adjacency list with the correct size and initialize it
    vector<vector<int>> adj(n+1,vector<int>());
    
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
    }

    vector<bool> visi(n, false);
    vector<bool> dfsvisi(n, false);

    for (int i = 0; i < n; i++) {
        if (!visi[i]) {
            if (dfs(visi, dfsvisi, i, adj)) {
                return 1;
            }
        }
    }

    return 0;
}
