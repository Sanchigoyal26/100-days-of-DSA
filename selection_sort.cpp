#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Selection Sort
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // swap smallest with current position
        swap(arr[i], arr[minIndex]);
    }

    // Output
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}