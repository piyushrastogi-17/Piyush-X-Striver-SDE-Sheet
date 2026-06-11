#include <iostream>
#include <vector>
#include <algorithm> 

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


void rotateClockwiseOptimal(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "--- OPTIMAL CLOCKWISE APPROACH (IN-PLACE) ---" << endl;
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    rotateClockwiseOptimal(matrix);

    cout << "Rotated Matrix (Clockwise - In-Place):" << endl;
    printMatrix(matrix);

    return 0;
}