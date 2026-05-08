#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> count;
    vector<pair<int, int>> arr; // {value, original index}

    void mergeSort(int left, int right) {

        if(left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        merge(left, mid, right);
    }

    void merge(int left, int mid, int right) {

        vector<pair<int, int>> temp;

        int i = left;
        int j = mid + 1;

        int rightCount = 0;

        while(i <= mid && j <= right) {

            // Right element is smaller
            if(arr[j].first < arr[i].first) {
                rightCount++;
                temp.push_back(arr[j]);
                j++;
            }
            else {
                count[arr[i].second] += rightCount;
                temp.push_back(arr[i]);
                i++;
            }
        }

        // Remaining left elements
        while(i <= mid) {
            count[arr[i].second] += rightCount;
            temp.push_back(arr[i]);
            i++;
        }

        // Remaining right elements
        while(j <= right) {
            temp.push_back(arr[j]);
            j++;
        }

        // Copy back
        for(int k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        count.resize(n, 0);

        // Store value with original index
        for(int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(0, n - 1);

        return count;
    }
};

int main() {

    vector<int> nums = {5, 2, 6, 1};

    Solution obj;

    vector<int> result = obj.countSmaller(nums);

    cout << "Count of smaller elements on right:\n";

    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}