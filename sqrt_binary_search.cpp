#include <iostream>
using namespace std;

int integerSqrt(int n) {
    int low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // To avoid overflow, use long long
        long long square = 1LL * mid * mid;

        if (square == n) {
            return mid;  // perfect square
        }
        else if (square < n) {
            ans = mid;   // store possible answer
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    cout << integerSqrt(n);

    return 0;
}