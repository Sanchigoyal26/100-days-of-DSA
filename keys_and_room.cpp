#include <iostream>
#include <vector>
using namespace std;

void dfs(int room, vector<vector<int>>& rooms, vector<int>& visited) {

    visited[room] = 1;

    for(int key : rooms[room]) {
        if(!visited[key]) {
            dfs(key, rooms, visited);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {

    int n = rooms.size();
    vector<int> visited(n, 0);

    dfs(0, rooms, visited);

    for(int i = 0; i < n; i++) {
        if(!visited[i])
            return false;
    }

    return true;
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> rooms(n);

    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;  // number of keys in room i

        for(int j = 0; j < k; j++) {
            int key;
            cin >> key;
            rooms[i].push_back(key);
        }
    }

    if(canVisitAllRooms(rooms))
        cout << "true";
    else
        cout << "false";

    return 0;
}