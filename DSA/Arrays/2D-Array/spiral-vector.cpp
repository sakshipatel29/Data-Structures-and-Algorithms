//TC : O(N*N) + O(N*N)
//SC: O(1 * 1)
#include <iostream>
#include <vector>
using namespace std;

vector<int> RotateMatrix(vector<vector<int>>& matrix, int n) {
    vector<int> ans;
    int left = 0, right = n - 1;
    int top = 0, bottom = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter matrix elements: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> ans = RotateMatrix(matrix, n);

    cout << "Spiral order traversal: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
