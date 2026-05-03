#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if we can place k cows with minimum distance = dist
bool canPlace(vector<int>& stalls, int k, int dist) {
    int count = 1; // first cow in first stall
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }

        if (count >= k) return true;
    }

    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> stalls(n);

    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    // Step 1: Sort stalls
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    // Binary Search on answer
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(stalls, k, mid)) {
            ans = mid;        // valid answer
            low = mid + 1;    // try bigger distance
        } else {
            high = mid - 1;   // reduce distance
        }
    }

    cout << ans;

    return 0;
}