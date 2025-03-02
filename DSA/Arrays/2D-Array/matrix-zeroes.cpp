//TC: O(2 * N * M)
//SC: O(N + M)

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> MatrixZero(vector<vector<int>>& matric, int n, int m){
    vector<int> col(n,0);
    vector<int> row(m,0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matric[i][j] == 0){
                col[i] = 1;
                row[j] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(col[i] == 1 || row[j] == 1){
                matric[i][j] = 0;
            }
        }
    }
    return matric;
}

int main() {
    int n;
    int m;
    cin >> n>> m;
    vector<vector<int>> matric(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> matric[i][j]; 
        }
    }
    matric = MatrixZero(matric, n , m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout <<  matric[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}