#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortColorsBruteForce(vector<int>& nums) {
    int n = nums.size();
    
    // Nested loops to compare every pair of elements
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j; // Track the smallest element
            }
        }
        // Swap the found minimum element with the first element
        swap(nums[i], nums[minIndex]);
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    
    cout << "Original array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    sortColorsBruteForce(nums);
    
    cout << "Sorted array (Brute Force): ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    return 0;
}