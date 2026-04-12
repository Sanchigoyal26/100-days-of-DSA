#include <iostream>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& st) {
    visited[node] = 1;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }

    st.push(node);
}

vector<int> topoSort(int V, vector<vector<int>>& adj) {
    vector<int> visited(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> result = topoSort(V, adj);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}