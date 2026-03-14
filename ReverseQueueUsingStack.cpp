#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {

    int N;
    cin >> N;

    queue<int> q;
    stack<int> st;

    // Input queue elements
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    // Step 1: Move queue → stack
    while(!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Move stack → queue
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Print reversed queue
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}