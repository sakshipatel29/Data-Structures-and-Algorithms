//TC: O(2 * N * M)
//SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> MatrixZero(vector<vector<int>>& matric, int n, int m){
    int col0 = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matric[i][j] == 0){
                matric[i][0] = 0;
                if(j != 0){
                    matric[0][j] = 0;
                }else{
                    col0 = 0;
                }
            }
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(matric[i][j] != 0){
                if((matric[i][0] == 0) || (matric[0][j] == 0)){
                    matric[i][j] = 0;
                }
            }
        }
    }
    if (matric[0][0] == 0){
        for (int j = 0; j < m; j++) matric[0][j] = 0;
    }
    if(col0 == 0){
        for (int i = 0; i < n; i++) matric[i][0] = 0;
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