#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Min heap: {weight, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> visited(n + 1, false);

    pq.push({0, 1}); // start from node 1
    int mst_weight = 0;

    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();

        if (visited[node]) continue;

        visited[node] = true;
        mst_weight += weight;

        for (auto [adjNode, edgeWeight] : adj[node]) {
            if (!visited[adjNode]) {
                pq.push({edgeWeight, adjNode});
            }
        }
    }

    cout << mst_weight << endl;

    return 0;
}