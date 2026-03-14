#include <iostream>
using namespace std;

#define MAX 100

class MinHeap {
    int heap[MAX];
    int size;

public:
    MinHeap() {
        size = 0;
    }

    // Heapify upward
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[parent] > heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else break;
        }
    }

    // Heapify downward
    void heapifyDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left] < heap[smallest])
                smallest = left;

            if (right < size && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else break;
        }
    }

    // Insert element
    void insert(int x) {
        if (size == MAX) return;

        heap[size] = x;
        heapifyUp(size);
        size++;
    }

    // Extract minimum element
    int extractMin() {
        if (size == 0) return -1;

        int minVal = heap[0];
        heap[0] = heap[size - 1];
        size--;

        heapifyDown(0);

        return minVal;
    }

    // Peek minimum
    int peek() {
        if (size == 0) return -1;
        return heap[0];
    }
};

int main() {
    int N;
    cin >> N;

    MinHeap h;

    for (int i = 0; i < N; i++) {
        string op;
        cin >> op;

        if (op == "insert") {
            int x;
            cin >> x;
            h.insert(x);
        }
        else if (op == "extractMin") {
            cout << h.extractMin() << endl;
        }
        else if (op == "peek") {
            cout << h.peek() << endl;
        }
    }

    return 0;
}