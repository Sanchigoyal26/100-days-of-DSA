#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:

    void addNum(int num) {

        left.push(num);
        right.push(left.top());
        left.pop();

        if(left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {

        if(left.size() > right.size())
            return left.top();

        return (left.top() + right.top()) / 2.0;
    }
};

int main() {

    MedianFinder mf;
    int n;
    cin >> n;

    while(n--) {
        string op;
        cin >> op;

        if(op == "add") {
            int x;
            cin >> x;
            mf.addNum(x);
        }
        else if(op == "median") {
            cout << mf.findMedian() << endl;
        }
    }

    return 0;
}