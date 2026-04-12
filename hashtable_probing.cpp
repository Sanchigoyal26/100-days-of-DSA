#include <iostream>
using namespace std;

class HashTable {
private:
    int m;
    vector<int> table;
    vector<bool> occupied;

public:
    HashTable(int size) {
        m = size;
        table.assign(m, -1);
        occupied.assign(m, false);
    }

    int hashFunction(int key) {
        return key % m;
    }

    void insert(int key) {
        for (int i = 0; i < m; i++) {
            int idx = (hashFunction(key) + i * i) % m;
            if (!occupied[idx]) {
                table[idx] = key;
                occupied[idx] = true;
                return;
            }
            if (table[idx] == key) return; // avoid duplicate insert
        }
    }

    bool search(int key) {
        for (int i = 0; i < m; i++) {
            int idx = (hashFunction(key) + i * i) % m;
            if (!occupied[idx]) return false;
            if (table[idx] == key) return true;
        }
        return false;
    }
};

int main() {
    int m, q;
    cin >> m >> q;

    HashTable ht(m);

    while (q--) {
        string op;
        int key;
        cin >> op >> key;

        if (op == "INSERT") {
            ht.insert(key);
        } else if (op == "SEARCH") {
            cout << (ht.search(key) ? "FOUND" : "NOT FOUND") << '\n';
        }
    }

    return 0;
}