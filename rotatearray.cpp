#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while(start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;   // handle k > n
        
        // Step 1: reverse whole array
        reverse(nums, 0, n-1);
        
        // Step 2: reverse first k elements
        reverse(nums, 0, k-1);
        
        // Step 3: reverse remaining elements
        reverse(nums, k, n-1);
    }
};
