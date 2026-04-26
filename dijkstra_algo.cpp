#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n+1];

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed
    }

    int source;
    cin >> source;

    vector<int> dist(n+1, INT_MAX);

    // min heap {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if(d > dist[node]) continue;

        for(auto [adjNode, weight] : adj[node]) {
            if(dist[node] + weight < dist[adjNode]) {
                dist[adjNode] = dist[node] + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    // print result (1 to n)
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}