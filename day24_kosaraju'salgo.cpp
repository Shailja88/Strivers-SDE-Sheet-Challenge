#include<bits/stdc++.h>

using namespace std;

 

void dfs(int v, vector<int> &visited, vector<vector<int>> &adj, stack<int> &st) {

    visited[v] = 1;

    for (auto n : adj[v]) {

        if (visited[n] == 0) {

            dfs(n, visited, adj, st);

        }

    }

    st.push(v);

}

 

void Dfs(int v, vector<int> &visited, vector<vector<int>> &adj, vector<int> &temp) {

    visited[v] = 1;

    temp.push_back(v);

    for (auto n : adj[v]) {

        if (visited[n] == 0) {

            Dfs(n, visited, adj, temp);

        }

    }

}

 

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges) {

    vector<vector<int>> adj(n);

    for (int i = 0; i < edges.size(); i++) {

        int u = edges[i][0], v = edges[i][1];

        adj[u].push_back(v);

    }

 

    // Toposort

    vector<int> visited(n, 0);

    stack<int> st;

    for (int i = 0; i < n; i++) {

        if (visited[i] == 0) {

            dfs(i, visited, adj, st);

        }

    }

 

    // Transpose

    vector<vector<int>> transpose(n);

    for (int i = 0; i < n; i++) {

        visited[i] = 0;

    }

    for (int i = 0; i < n; i++) {

        for (auto n : adj[i]) {

            transpose[n].push_back(i);

        }

    }

 

    vector<vector<int>> ans;

    while (!st.empty()) {

        vector<int> temp;

        int c = st.top();

        st.pop();

        if (visited[c] == 1) continue;

        Dfs(c, visited, transpose, temp);

        ans.push_back(temp);

    }

    return ans;

}

 
