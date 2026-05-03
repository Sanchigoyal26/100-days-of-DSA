#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if we can paint with k painters within maxTime
bool isPossible(vector<int>& boards, int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) return false;

        if (currentTime + boards[i] <= maxTime) {
            currentTime += boards[i];
        } else {
            painters++;
            currentTime = boards[i];

            if (painters > k) return false;
        }
    }

    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> boards(n);
    for (int i = 0; i < n; i++) {
        cin >> boards[i];
    }

    int low = *max_element(boards.begin(), boards.end());
    int high = 0;

    for (int x : boards) high += x;

    int ans = high;

    // Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1; // try smaller time
        } else {
            low = mid + 1;  // increase time
        }
    }

    cout << ans;
    return 0;
}