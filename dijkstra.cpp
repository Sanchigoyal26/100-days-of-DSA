#include <iostream>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {
    vector<int> dist(V, INT_MAX);

    // min-heap: {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        // skip outdated entries
        if (d > dist[node]) continue;

        for (auto &it : adj[node]) {
            int neighbor = it.first;
            int weight = it.second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    return dist;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    // input edges: u v w
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove this line if directed
    }

    int src;
    cin >> src;

    vector<int> dist = dijkstra(V, adj, src);

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

    return 0;
}