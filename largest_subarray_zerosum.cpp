#include <iostream>
using namespace std;

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // If sum becomes 0 → whole subarray from 0 to i
        if (sum == 0) {
            maxLen = i + 1;
        }

        // If sum seen before → subarray exists
        if (mp.find(sum) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum]);
        } else {
            // Store first occurrence only
            mp[sum] = i;
        }
    }

    cout << maxLen;
    return 0;
}