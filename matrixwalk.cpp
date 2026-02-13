#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    cout << "Spiral Traversal: ";

    while(top <= bottom && left <= right) {

        // Left to Right
        for(int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;

        // Top to Bottom
        for(int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;

        // Right to Left
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        // Bottom to Top
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }

    return 0;
}
