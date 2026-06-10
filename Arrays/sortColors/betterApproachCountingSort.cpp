#include <iostream>
#include <vector>

using namespace std;

void sortColorsCounting(vector<int>& nums) {
    int zeroCount = 0, oneCount = 0, twoCount = 0;
    
    // Pass 1: Count frequencies
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) zeroCount++;
        else if(nums[i] == 1) oneCount++;
        else twoCount++;
    }
    
    // Pass 2: Overwrite original array
    int idx = 0;
    while(zeroCount--) nums[idx++] = 0;
    while(oneCount--)  nums[idx++] = 1;
    while(twoCount--)  nums[idx++] = 2;
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColorsCounting(nums);
    
    cout << "Sorted using Counting Sort: ";
    for(int x : nums) cout << x << " ";
    cout << endl;
    return 0;
}