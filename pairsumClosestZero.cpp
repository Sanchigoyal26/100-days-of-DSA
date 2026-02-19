#include <iostream>
using namespace std;

pair<int,int> closestToZero(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int left = 0;
    int right = arr.size() - 1;

    int minSum = INT_MAX;
    pair<int,int> ans;

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            ans = {arr[left], arr[right]};
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    return ans;
}

int main() {
    vector<int> arr = {-8, -66, -60, 10, 55, 85};
    pair<int,int> res = closestToZero(arr);
    cout << res.first << " " << res.second;
}
