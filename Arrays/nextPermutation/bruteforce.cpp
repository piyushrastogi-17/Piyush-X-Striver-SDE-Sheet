#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Forward declaration of the backtracking helper function
void backtrack(vector<int>& nums, int start, vector<vector<int>>& result);

// The core logic function (extracted from the class)
void nextPermutation(vector<int>& nums) {
    vector<vector<int>> allPermutations;
    
    // Step 1: Generate all unique permutations
    backtrack(nums, 0, allPermutations);
    
    // Step 2: Sort the permutations lexicographically
    sort(allPermutations.begin(), allPermutations.end());
    
    // Step 3: Find the current array in the sorted list
    for (int i = 0; i < allPermutations.size(); i++) {
        if (allPermutations[i] == nums) {
            // Step 4: Get the next permutation (wrap around to 0 if it's the last one)
            vector<int> next = (i == allPermutations.size() - 1) 
                               ? allPermutations[0] 
                               : allPermutations[i + 1];
            
            // Copy the result back into the original nums array
            nums = next;
            return;
        }
    }
}

// Helper function to generate permutations via backtracking
void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size()) {
        // Avoid adding duplicates if the input contains duplicate elements
        if (find(result.begin(), result.end(), nums) == result.end()) {
            result.push_back(nums);
        }
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        backtrack(nums, start + 1, result);
        swap(nums[start], nums[i]); // Backtrack (undo swap)
    }
}

int main() {
    // Example input array
    vector<int> nums = {1, 2, 3};

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Modify the array to its next permutation
    nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}