#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxSubArrayOptimal(vector<int>& nums) {
    int maxSum = INT_MIN;
    int currentSum = 0;

    // A single loop to scan the array from left to right
    for (int i = 0; i < nums.size(); i++) {
        currentSum += nums[i];
        
        // Record the maximum sum found so far
        maxSum = max(maxSum, currentSum);
        
        // If the running sum becomes negative, discard it immediately
        if (currentSum < 0) {
            currentSum = 0;
        }
    }
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    cout << "--- Optimal Approach (Kadane's) ---" << endl;
    cout << "Maximum Subarray Sum: " << maxSubArrayOptimal(nums) << endl;
    
    return 0;
}