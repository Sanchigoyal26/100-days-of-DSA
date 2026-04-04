#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {

    int m = image.size();
    int n = image[0].size();

    if(r < 0 || c < 0 || r >= m || c >= n)
        return;

    if(image[r][c] != oldColor)
        return;

    image[r][c] = newColor;

    dfs(image, r+1, c, oldColor, newColor);
    dfs(image, r-1, c, oldColor, newColor);
    dfs(image, r, c+1, oldColor, newColor);
    dfs(image, r, c-1, oldColor, newColor);
}

int main() {

    int m, n;
    cin >> m >> n;

    vector<vector<int>> image(m, vector<int>(n));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> image[i][j];
        }
    }

    int sr, sc, color;
    cin >> sr >> sc >> color;

    int oldColor = image[sr][sc];

    if(oldColor != color)
        dfs(image, sr, sc, oldColor, color);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}