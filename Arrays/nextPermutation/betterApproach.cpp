#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = -1;

    
    for (int k = n - 2; k >= 0; k--) {
        if (nums[k] < nums[k + 1]) {
            i = k; // Found our pivot index
            break;
        }
    }

    
    if (i != -1) {
        
        for (int j = n - 1; j > i; j--) {
            if (nums[j] > nums[i]) {
                swap(nums[i], nums[j]); 
                break;                  
            }
        }
    }

    
    int start = i + 1;
    int end = n - 1;
    for (; start < end; start++, end--) {
        swap(nums[start], nums[end]);
    }
}

int main() {
    vector<int> nums = {1, 2, 3};

    cout << "Original array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}