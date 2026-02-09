#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];  // assuming max size 100

    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int pos;
    cout << "Enter position to delete (1-based index): ";
    cin >> pos;

    // Check for valid position
    if(pos < 1 || pos > n) {
        cout << "Invalid position!";
        return 0;
    }

    // Shift elements left
    for(int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;  // reduce size

    cout << "Array after deletion:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
