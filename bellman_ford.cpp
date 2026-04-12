#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cin >> src;

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto &[u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check negative cycle
    for (auto &[u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "NEGATIVE CYCLE";
            return 0;
        }
    }

    // Print distances
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

    return 0;
}