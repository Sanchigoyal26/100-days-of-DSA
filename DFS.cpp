#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, vector<vector<int>>& adj, vector<int>& visited) {
    visited[v] = 1;
    cout << v << " ";

    for(int neighbor : adj[v]) {
        if(!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    // reading adjacency list
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k; // number of neighbors

        for(int j = 0; j < k; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }

    int s;
    cin >> s; // starting vertex

    vector<int> visited(n, 0);

    cout << "DFS Traversal: ";
    dfs(s, adj, visited);

    return 0;
}