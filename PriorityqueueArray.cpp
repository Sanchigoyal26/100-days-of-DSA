#include <iostream>
using namespace std;

#define MAX 100

class PriorityQueue {
    int arr[MAX];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    // Insert element
    void insert(int x) {
        if (size == MAX) return;

        int i = size - 1;

        // shift elements to maintain sorted order
        while (i >= 0 && arr[i] > x) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = x;
        size++;
    }

    // Delete highest priority (smallest element)
    int deleteElement() {
        if (size == 0) return -1;

        int val = arr[0];

        for (int i = 1; i < size; i++)
            arr[i - 1] = arr[i];

        size--;
        return val;
    }

    // Peek element
    int peek() {
        if (size == 0) return -1;
        return arr[0];
    }
};

int main() {
    int N;
    cin >> N;

    PriorityQueue pq;

    for (int i = 0; i < N; i++) {
        string op;
        cin >> op;

        if (op == "insert") {
            int x;
            cin >> x;
            pq.insert(x);
        }
        else if (op == "delete") {
            cout << pq.deleteElement() << endl;
        }
        else if (op == "peek") {
            cout << pq.peek() << endl;
        }
    }

    return 0;
}