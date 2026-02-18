#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &nums, int start, int end){
    while(start < end){
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

void rotate(vector<int> &nums, int k){
    int n = nums.size();
    k = k % n;               // handle k > n

    reverseArray(nums, 0, n-1);   // step 1
    reverseArray(nums, 0, k-1);   // step 2
    reverseArray(nums, k, n-1);   // step 3
}

int main(){
    int n,k;
    cin >> n;
    vector<int> nums(n);

    for(int i=0;i<n;i++)
        cin >> nums[i];

    cin >> k;

    rotate(nums,k);

    for(int x : nums)
        cout << x << " ";
}
