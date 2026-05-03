#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<float> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // values in [0,1)
    }

    // 1) Create n buckets
    vector<vector<float>> buckets(n);

    // 2) Put elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];  // bucket index
        buckets[index].push_back(arr[i]);
    }

    // 3) Sort each bucket
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 4) Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (float x : buckets[i]) {
            arr[k++] = x;
        }
    }

    // Print sorted array
    for (float x : arr) {
        cout << x << " ";
    }

    return 0;
}