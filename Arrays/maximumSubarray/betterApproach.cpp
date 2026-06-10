#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxSubArrayBetter(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;

    // Loop 1: Pick the starting point
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        
        // Loop 2: Move the ending point and reuse the current running sum
        for (int j = i; j < n; j++) {
            currentSum += nums[j]; 
            maxSum = max(maxSum, currentSum);
        }
    }
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    cout << "--- Better Approach ---" << endl;
    cout << "Maximum Subarray Sum: " << maxSubArrayBetter(nums) << endl;
    
    return 0;
}