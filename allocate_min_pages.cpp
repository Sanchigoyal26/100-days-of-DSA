#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if allocation is possible with given maxPages
bool isPossible(vector<int>& books, int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        if (books[i] > maxPages) return false;

        if (pagesSum + books[i] <= maxPages) {
            pagesSum += books[i];
        } else {
            students++;
            pagesSum = books[i];

            if (students > m) return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> books(n);

    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    // Edge case
    if (m > n) {
        cout << -1;
        return 0;
    }

    int low = *max_element(books.begin(), books.end());
    int high = 0;

    for (int x : books) high += x;

    int ans = high;

    // Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(books, n, m, mid)) {
            ans = mid;
            high = mid - 1; // try smaller max
        } else {
            low = mid + 1;  // increase limit
        }
    }

    cout << ans;
    return 0;
}