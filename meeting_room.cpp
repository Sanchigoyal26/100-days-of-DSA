#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty())
        return 0;

    // Sort by start time
    sort(intervals.begin(), intervals.end());

    // Min-heap for end times
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Add first meeting end time
    minHeap.push(intervals[0][1]);

    // Process remaining meetings
    for (int i = 1; i < intervals.size(); i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // If a room gets free, reuse it
        if (start >= minHeap.top()) {
            minHeap.pop();
        }

        // Allocate current meeting room
        minHeap.push(end);
    }

    // Heap size = minimum rooms required
    return minHeap.size();
}

int main() {
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};

    cout << "Minimum meeting rooms required: "
         << minMeetingRooms(intervals);

    return 0;
}