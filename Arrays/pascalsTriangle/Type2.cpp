#include <iostream>
#include <vector>
using namespace std;

vector<int> pascalTriangleArray(int n) {
    vector<int> arr;
    int ans = 1;
    arr.push_back(ans);
    for(int i=1; i<n; i++) {
        ans = ans * (n-i);
        ans = ans / i;
        arr.push_back(ans);
    }
    return arr;
}
int main() {
    int n = 6;
    vector<int> arr = pascalTriangleArray(n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}