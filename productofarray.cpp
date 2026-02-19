#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);

    // Step 1: prefix product
    ans[0] = 1;
    for(int i = 1; i < n; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }

    // Step 2: suffix product
    int suffix = 1;
    for(int i = n-1; i >= 0; i--){
        ans[i] = ans[i] * suffix;
        suffix *= nums[i];
    }

    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for(int i=0;i<n;i++)
        cin >> nums[i];

    vector<int> res = productExceptSelf(nums);

    for(int x : res)
        cout << x << " ";
}
