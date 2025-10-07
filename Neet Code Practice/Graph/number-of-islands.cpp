#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//TC: O(N*M)
//SC: O(N*M) + O(N*M)

class Solution {
    public:
        void bfs(int i, int j, vector<vector<char>>& grid,
                 vector<vector<int>>& vis) {
            int n = grid.size();
            int m = grid[0].size();
            queue<pair<int, int>> q;
            vis[i][j] = 1;
            q.push({i, j});
    
            int dcol[] = {0, 1, 0, -1};
            int drow[] = {-1, 0, 1, 0};
    
            while (!q.empty()) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nrow = row + drow[k];
                    int ncol = col + dcol[k];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
        int numIslands(vector<vector<char>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> vis(n, vector<int>(m, 0));
            int count = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!vis[i][j] && grid[i][j] == '1') {
                        count++;
                        bfs(i, j, grid, vis);
                    }
                }
            }
            return count;
        }
    };