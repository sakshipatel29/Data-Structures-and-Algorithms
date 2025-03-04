//TC: O(N/2*N/2) + O(N/2 * N)
//SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> RotateMatrix(vector<vector<int>>& matrix, int n){
    for(int i = 0; i <= n-2; i++){
        for(int j = i+1; j <= n-1; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i = 0; i < n; i++){
        int p1 = 0, p2 = n - 1;
        while(p1 < p2){
            swap(matrix[i][p1], matrix[i][p2]);
            p1++;
            p2--;
        }
    }
    return matrix;
}

int main() {
    int n = 4;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    RotateMatrix(matrix, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << endl;
    }
    return 0;
}