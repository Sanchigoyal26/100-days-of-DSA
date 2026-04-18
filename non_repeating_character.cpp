#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);

    // Count frequency
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Find first non-repeating character
    for (char c : s) {
        if (freq[c - 'a'] == 1) {
            cout << c;
            return 0;
        }
    }

    cout << '$';
    return 0;
}