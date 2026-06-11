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

void rotateAnticlockwiseOptimal(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Step 1: Matrix ka Transpose lena
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    
    int top = 0;
    int bottom = n - 1;
    while (top < bottom) {
        swap(matrix[top], matrix[bottom]); 
        top++;
        bottom--;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "--- OPTIMAL ANTICLOCKWISE APPROACH (IN-PLACE) ---" << endl;
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    rotateAnticlockwiseOptimal(matrix);

    cout << "Rotated Matrix (Anticlockwise - In-Place):" << endl;
    printMatrix(matrix);

    return 0;
}