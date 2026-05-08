#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

    // If empty
    if(intervals.empty())
        return {};

    // Sort intervals by starting time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;

    // Add first interval
    merged.push_back(intervals[0]);

    // Traverse remaining intervals
    for(int i = 1; i < intervals.size(); i++) {

        // Current interval
        int start = intervals[i][0];
        int end = intervals[i][1];

        // Last merged interval
        int lastEnd = merged.back()[1];

        // Overlapping intervals
        if(start <= lastEnd) {
            merged.back()[1] = max(lastEnd, end);
        }
        // Non-overlapping
        else {
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

int main() {

    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    vector<vector<int>> result = mergeIntervals(intervals);

    cout << "Merged Intervals:\n";

    for(auto interval : result) {
        cout << "[" << interval[0] << ", "
             << interval[1] << "] ";
    }

    return 0;
}