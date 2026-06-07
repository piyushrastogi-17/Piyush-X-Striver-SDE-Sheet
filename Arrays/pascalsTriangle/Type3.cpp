#include <iostream>
#include <vector>
using namespace std;

vector<int> generateRow(int n) {
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
vector<vector<int> > pascalTriangle(int N) {
    vector<vector<int> > ans;
    for(int i=1; i<=N; i++) {
        vector<int> temp = generateRow(i);
        ans.push_back(temp);
    }
    return ans;
}
int main() {
    int n = 6;
    vector<vector<int> > ans = pascalTriangle(n);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}