#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {

    vector<int> freq(26,0);

    for(char t : tasks)
        freq[t - 'A']++;

    int maxFreq = *max_element(freq.begin(), freq.end());

    int countMax = 0;
    for(int f : freq)
        if(f == maxFreq)
            countMax++;

    int result = (maxFreq - 1) * (n + 1) + countMax;

    return max((int)tasks.size(), result);
}

int main() {

    int n, m;
    cin >> m;

    vector<char> tasks(m);

    for(int i=0;i<m;i++)
        cin >> tasks[i];

    cin >> n;

    cout << leastInterval(tasks,n);

    return 0;
}