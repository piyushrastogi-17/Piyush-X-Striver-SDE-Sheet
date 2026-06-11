#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervalsBrute(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n <= 1) return intervals;

    // Step 1: Sort the intervals
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        
        for (int j = i + 1; j < n; j++) {
            if (intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
            } else {
                break; 
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    
    cout << "--- Brute Force Approach ---" << endl;
    vector<vector<int>> result = mergeIntervalsBrute(intervals);
    
    cout << "Merged Intervals: " << endl;
    for (const auto& it : result) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}