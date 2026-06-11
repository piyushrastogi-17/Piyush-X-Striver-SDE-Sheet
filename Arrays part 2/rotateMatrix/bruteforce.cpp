#include <iostream>
#include <vector>

using namespace std;


void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}


vector<vector<int>> rotateClockwiseBrute(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    vector<vector<int>> ans(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[j][n - 1 - i] = matrix[i][j];
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "--- BRUTE FORCE APPROACH ---" << endl;
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    vector<vector<int>> rotatedMatrix = rotateClockwiseBrute(matrix);

    cout << "Rotated Matrix (Clockwise - Brute Force):" << endl;
    printMatrix(rotatedMatrix);

    return 0;
}