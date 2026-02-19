#include <iostream>
#include<vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int totalSum = 0;
    
    int currMax = 0, maxSum = INT_MIN;
    int currMin = 0, minSum = INT_MAX;
    
    for(int num : nums) {
        // Kadane for max subarray
        currMax = max(num, currMax + num);
        maxSum = max(maxSum, currMax);
        
        // Kadane for min subarray
        currMin = min(num, currMin + num);
        minSum = min(minSum, currMin);
        
        totalSum += num;
    }
    
    // If all elements are negative
    if(maxSum < 0)
        return maxSum;
    
    return max(maxSum, totalSum - minSum);
}
