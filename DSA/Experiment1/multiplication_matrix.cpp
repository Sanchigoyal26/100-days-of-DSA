#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of Matrix 1: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns of Matrix 2: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible!";
        return 0;
    }

    
    int A[r1][c1], B[r2][c2];
    int C[r1][c2] = {0}; 

    cout << "Enter Matrix 1 elements:\n";
    for(int i=0;i<r1;i++)
        for(int j=0;j<c1;j++)
            cin >> *(*(A+i)+j);   // pointer access

    cout << "Enter Matrix 2 elements:\n";
    for(int i=0;i<r2;i++)
        for(int j=0;j<c2;j++)
            cin >> *(*(B+i)+j);   // pointer access

    // multiplication
    for(int i=0;i<r1;i++) {
        for(int j=0;j<c2;j++) {
            for(int k=0;k<c1;k++) {
                *(*(C+i)+j) += (*(*(A+i)+k)) * (*(*(B+k)+j));
            }
        }
    }

    cout << "\nResult Matrix:\n";
    for(int i=0;i<r1;i++) {
        for(int j=0;j<c2;j++)
            cout << *(*(C+i)+j) << " ";
        cout << endl;
    }

    return 0;
}