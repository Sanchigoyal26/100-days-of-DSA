#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int n, vector<vector<int>> &adj, int s) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<vector<int>> adj(n);

    cout << "Enter adjacency list:\n";
    for (int i = 0; i < n; i++) {
        int m;
        cout << "Number of neighbors of node " << i << ": ";
        cin >> m;

        cout << "Enter neighbors: ";
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }

    int s;
    cout << "Enter source node: ";
    cin >> s;

    BFS(n, adj, s);

    return 0;
}