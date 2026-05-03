#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // 1) Find max
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    // 2) Frequency array
    vector<int> freq(maxVal + 1, 0);
    for (int x : arr) freq[x]++;

    // 3) Prefix sums
    for (int i = 1; i <= maxVal; i++) {
        freq[i] += freq[i - 1];
    }

    // 4) Build output (right to left for stability)
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        int val = arr[i];
        int pos = freq[val] - 1; // correct index
        output[pos] = val;
        freq[val]--;
    }

    // 5) Copy back
    for (int i = 0; i < n; i++) arr[i] = output[i];

    // Print sorted array
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}