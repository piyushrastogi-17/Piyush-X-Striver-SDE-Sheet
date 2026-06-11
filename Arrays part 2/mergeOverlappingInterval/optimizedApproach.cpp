#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervalsBest(vector<vector<int>>& intervals) {
    
    if (intervals.empty()) return {};

    
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    
    for (const auto& interval : intervals) {
        if (ans.empty() || interval[0] > ans.back()[1]) {
            ans.push_back(interval);
        } 
        
        else {
            ans.back()[1] = max(ans.back()[1], interval[1]);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    
    cout << "--- Best/Optimal Approach (In-Place) ---" << endl;
    vector<vector<int>> result = mergeIntervalsBest(intervals);
    
    cout << "Merged Intervals: " << endl;
    for (const auto& it : result) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}