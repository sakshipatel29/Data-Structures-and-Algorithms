#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//TC: O(N*M)
//SC: O(N*M) + O(N*M)

class Solution {
    public:
        int islandPerimeter(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> vis(n, vector<int>(m, 0)); // O(N*M)
            queue<pair<int, int>> q; // O(N*M)
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 1) {
                        vis[i][j] = 1;
                        q.push({i, j});
                        break;
                    }
                }
            } // O(N*M)
            int dcol[] = {0, 1, 0, -1};
            int drow[] = {-1, 0, 1, 0};
            int area = 0;
            while (!q.empty()) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                int count = 0;
                for (int i = 0; i < 4; i++) { // O(4)
                    int nrow = r + drow[i];
                    int ncol = c + dcol[i];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == 1) {
                        count++;
                        if(vis[nrow][ncol] == 0){
                            vis[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }
                    }
                }
                area += (4 - count);
            }
            return area;
        }
    };