#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);

    for (char c : s) {
        freq[c - 'a']++;

        if (freq[c - 'a'] == 2) {
            cout << c;
            return 0;
        }
    }

    cout << -1;
    return 0;
}