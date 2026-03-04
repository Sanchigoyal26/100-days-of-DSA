#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    void push(int val) {
        st.push(val);
        if(minSt.empty() || val <= minSt.top())
            minSt.push(val);
    }

    void pop() {
        if(st.top() == minSt.top())
            minSt.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack s;

    s.push(-2);
    s.push(0);
    s.push(-3);

    cout << "Min: " << s.getMin() << endl;

    s.pop();

    cout << "Top: " << s.top() << endl;
    cout << "Min: " << s.getMin() << endl;

    return 0;
}