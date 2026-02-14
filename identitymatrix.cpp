#include<iostream>
#include<vector>
using namespace std;
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int matrix[n][n];

    cout << "Enter elements of matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    bool isIdentity = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j && matrix[i][j] != 1) {
                isIdentity = false;
                break;
            }
            if(i != j && matrix[i][j] != 0) {
                isIdentity = false;
                break;
            }
        }
    }

    if(isIdentity)
        cout << "Matrix is an Identity Matrix";
    else
        cout << "Matrix is NOT an Identity Matrix";

    return 0;
}
