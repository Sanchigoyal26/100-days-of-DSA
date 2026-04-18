#include <iostream>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int nei : adj[node]) {
        if (!visited[nei]) {
            dfs(nei, adj, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);

    // Start DFS from node 1
    dfs(1, adj, visited);

    // Check if all nodes are visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NOT CONNECTED";
            return 0;
        }
    }

    cout << "CONNECTED";
    return 0;
}