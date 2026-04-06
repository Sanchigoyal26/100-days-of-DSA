#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited){
    
    visited[node] = true;
    
    for(int neighbor : adj[node]){
        
        if(!visited[neighbor]){
            if(dfs(neighbor, node, adj, visited))
                return true;
        }
        
        else if(neighbor != parent){
            return true;
        }
    }
    
    return false;
}

int main(){
    
    int V, E;
    cin >> V >> E;
    
    vector<vector<int>> adj(V);
    
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> visited(V, false);
    
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            if(dfs(i, -1, adj, visited)){
                cout << "YES";
                return 0;
            }
        }
    }
    
    cout << "NO";
}