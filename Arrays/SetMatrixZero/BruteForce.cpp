#include <iostream>
#include <vector>

using namespace std;

// Approach 1: BruteForce : additional space O(N*N*N)
vector<vector<int>> setMatrixZeros(vector<vector<int> > &mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    vector<vector<int> > vec = mat; 
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 0) {
                for(int k = 0; k < m; k++) {
                    vec[i][k] = 0;
                }
                for(int k = 0; k < n; k++) {
                    vec[k][j] = 0;
                }
            }
        }
    }
    return vec; 
}

// Approach 2: Helper functions
void markRow(vector<vector<int> > &mat, int i, int m) {
    for(int j=0; j<m; j++) {
        if(mat[i][j] != 0) {
            mat[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int> > &mat, int j, int n) {
    for(int i=0; i<n; i++) {
        if(mat[i][j] != 0) {
            mat[i][j] = -1;
        }
    }
}

// Bruteforce Approach 2 O(N*M)
void setMatrixZeros2(vector<vector<int> > &mat) {
    int n = mat.size();
    int m = mat[0].size();

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == 0) {
                markRow(mat, i, m);
                markCol(mat, j, n);
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == -1) {
                mat[i][j] = 0;
            }
        }
    }
}

int main() {
    // Original Matrix
    vector<vector<int> > mat1 = {{0,1,2,0}, {3,4,5,2}, {1,3,4,5}};
    vector<vector<int> > mat2 = mat1; // Doosre function ke liye copy banayi
    
    // 1. Pehle function ki calling aur printing
    cout << "Approach 1 Output:" << endl;
    vector<vector<int> > ans1 = setMatrixZeros(mat1);
    for(int i = 0; i < ans1.size(); i++) {
        for(int j = 0; j < ans1[0].size(); j++) {
            cout << ans1[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "-----------------" << endl;

    // 2. Doosre function ki calling aur printing
    cout << "Approach 2 Output:" << endl;
    setMatrixZeros2(mat2); // Ye void hai, mat2 ke andar hi changes kar dega
    for(int i = 0; i < mat2.size(); i++) {
        for(int j = 0; j < mat2[0].size(); j++) {
            cout << mat2[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}