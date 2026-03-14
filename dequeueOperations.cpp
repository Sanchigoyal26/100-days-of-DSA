#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N;
    cin >> N;

    deque<int> dq;

    while (N--) {
        string op;
        cin >> op;

        if (op == "push_front") {
            int x;
            cin >> x;
            dq.push_front(x);
        }

        else if (op == "push_back") {
            int x;
            cin >> x;
            dq.push_back(x);
        }

        else if (op == "pop_front") {
            if (dq.empty())
                cout << -1 << endl;
            else {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }

        else if (op == "pop_back") {
            if (dq.empty())
                cout << -1 << endl;
            else {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        }

        else if (op == "front") {
            if (dq.empty()) cout << -1 << endl;
            else cout << dq.front() << endl;
        }

        else if (op == "back") {
            if (dq.empty()) cout << -1 << endl;
            else cout << dq.back() << endl;
        }

        else if (op == "size") {
            cout << dq.size() << endl;
        }
    }

    // Print final deque
    if (!dq.empty()) {
        for (int x : dq)
            cout << x << " ";
    }

    return 0;
}