#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxSubArrayBruteForce(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;

    // Loop 1: Pick the starting point of the subarray
    for (int i = 0; i < n; i++) {
        // Loop 2: Pick the ending point of the subarray
        for (int j = i; j < n; j++) {
            int currentSum = 0;
            
            // Loop 3: Calculate the sum of elements from index i to j
            for (int k = i; k <= j; k++) {
                currentSum += nums[k];
            }
            maxSum = max(maxSum, currentSum);
        }
    }
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    cout << "--- Brute Force Approach ---" << endl;
    cout << "Maximum Subarray Sum: " << maxSubArrayBruteForce(nums) << endl;
    
    return 0;
}