#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervalsBetter(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> mergedIntervals;
    vector<int> tempInterval = intervals[0];

    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= tempInterval[1]) {
            
            tempInterval[1] = max(tempInterval[1], intervals[i][1]);
        } else {
            mergedIntervals.push_back(tempInterval);
            tempInterval = intervals[i];
        }
    }
    // Push the final remaining interval
    mergedIntervals.push_back(tempInterval);

    return mergedIntervals;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    
    cout << "Better Approach (Using Temp)" << endl;
    vector<vector<int>> result = mergeIntervalsBetter(intervals);
    
    cout << "Merged Intervals: " << endl;
    for (const auto& it : result) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}