#include <iostream>
using namespace std;

// Lower Bound: first index where arr[i] >= x
int lowerBound(vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;
    int ans = arr.size();

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

// Upper Bound: first index where arr[i] > x
int upperBound(vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;
    int ans = arr.size();

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > x) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int x;
    cin >> x;

    int lb = lowerBound(arr, x);
    int ub = upperBound(arr, x);

    cout << lb << " " << ub << endl;

    return 0;
}