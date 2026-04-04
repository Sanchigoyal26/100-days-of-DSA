#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);   // remove this line if graph is directed
    }

    // Print adjacency list
    for(int i = 0; i < n; i++) {
        cout << i << " -> ";
        for(int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}