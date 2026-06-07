#include <iostream>
#include <vector>
using namespace std;

// better Approach O(N*M)
void setZeros(vector<vector<int> > &matrix)
{
	// Write your code here.
	int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
}

int main() {
    // initialization syntax
    vector<vector<int> > mat = {{0,1,2,0}, {3,4,5,2}, {1,3,4,5}};
    
    setZeros(mat);
    
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}