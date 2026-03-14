#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

public:
    KthLargest(int k, vector<int> &nums) {
        this->k = k;

        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);

        if (pq.size() > k)
            pq.pop();

        return pq.top();
    }
};

int main() {
    int k, n;
    cin >> k >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    KthLargest obj(k, nums);

    int q;
    cin >> q;

    while (q--) {
        int val;
        cin >> val;
        cout << obj.add(val) << endl;
    }

    return 0;
}