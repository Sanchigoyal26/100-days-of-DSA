#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    int missingNum(vector<int>& arr) {
      int n = arr.size() + 1;
        int xor1 = 0, xor2 = 0;

        for (int i = 1; i <= n; i++)
            xor1 ^= i;

        for (int num : arr)
            xor2 ^= num;

        return xor1 ^ xor2;
    }
};