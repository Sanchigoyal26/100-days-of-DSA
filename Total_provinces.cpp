#include <iostream>
#include <vector>
using namespace std;

void dfs(int city, vector<vector<int>>& graph, vector<int>& visited) {

    visited[city] = 1;

    for(int i = 0; i < graph.size(); i++) {
        if(graph[city][i] == 1 && !visited[i]) {
            dfs(i, graph, visited);
        }
    }
}

int findProvinces(vector<vector<int>>& graph) {

    int n = graph.size();
    vector<int> visited(n, 0);
    int provinces = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, graph, visited);
            provinces++;
        }
    }

    return provinces;
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << findProvinces(graph);

    return 0;
}