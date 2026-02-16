#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> freq;

    // Count frequency
    for(int i = 0; i < n; i++)
        freq[arr[i]]++;

    // Print result
    for(auto it : freq)
        cout << it.first << ":" << it.second << endl;

    return 0;
}

