#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {

    unordered_map<int,int> freq;

    // Count frequency
    for(int n : nums)
        freq[n]++;

    // Min heap (frequency, number)
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    for(auto p : freq) {
        pq.push({p.second, p.first});

        if(pq.size() > k)
            pq.pop();
    }

    vector<int> result;

    while(!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }

    return result;
}

int main() {

    int n, k;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cin >> k;

    vector<int> ans = topKFrequent(nums, k);

    for(int x : ans)
        cout << x << " ";

    return 0;
}