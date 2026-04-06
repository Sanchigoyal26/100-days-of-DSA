#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int,int>> q;
    int fresh = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2)
                q.push({i,j});
            if(grid[i][j]==1)
                fresh++;
        }
    }

    int minutes = 0;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    while(!q.empty() && fresh>0){
        int size=q.size();

        while(size--){
            auto p=q.front();
            q.pop();

            int x=p.first;
            int y=p.second;

            for(auto &d:dir){
                int nx=x+d[0];
                int ny=y+d[1];

                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1){
                    grid[nx][ny]=2;
                    fresh--;
                    q.push({nx,ny});
                }
            }
        }
        minutes++;
    }

    if(fresh>0) return -1;
    return minutes;
}

int main(){
    int m,n;
    cout<<"Enter rows and columns: ";
    cin>>m>>n;

    vector<vector<int>> grid(m,vector<int>(n));

    cout<<"Enter grid values:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    cout<<"Minimum minutes: "<<orangesRotting(grid);

    return 0;
}