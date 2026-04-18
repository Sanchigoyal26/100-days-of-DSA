#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> freq;
    string name;

    // Count votes
    for (int i = 0; i < n; i++) {
        cin >> name;
        freq[name]++;
    }

    string winner = "";
    int maxVotes = 0;

    for (auto &p : freq) {
        string candidate = p.first;
        int votes = p.second;

        if (votes > maxVotes) {
            maxVotes = votes;
            winner = candidate;
        }
        else if (votes == maxVotes && candidate < winner) {
            winner = candidate; // lexicographically smaller
        }
    }

    cout << winner << " " << maxVotes;
    return 0;
}