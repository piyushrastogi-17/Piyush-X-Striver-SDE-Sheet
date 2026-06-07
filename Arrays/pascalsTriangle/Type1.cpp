#include <iostream>
using namespace std;

// type 1
long long pascalTriangleValue(int n, int r) {
    long long res = 1;
    for(int i=0; i<r; i++) {
        res = res * (n-i);
        res = res / (i+1);
    }
    return res;
}
int main() {
    int n,r;
    cout << "Enter the value of n:";
    cin >> n;
    cout << "Enter the value of r:";
    cin >> r;
    long long ans = pascalTriangleValue(n, r);
    cout << ans << endl;
    
    return 0;
}