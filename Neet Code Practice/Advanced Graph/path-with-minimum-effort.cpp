#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//TC: O(N*M*log(N*M))
//SC: O(N*M) + O(N*M)

class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            int n = heights.size();
            int m = heights[0].size();
    
            vector<vector<int>> dist(n, vector<int>(m, 1e9)); // O(N*M)
            priority_queue < pair<int, pair<int, int>>,
                vector<pair<int, pair<int, int>>>,
                greater<pair<int, pair<int, int>>>> pq; // O(N*M)
    
            int dcol[] = {0, 1, 0, -1};
            int drow[] = {-1, 0, 1, 0};
            int cost = 0;
            pq.push({0, {0, 0}});
            while (!pq.empty()) { // O(N*M*log(N*M)) // N*M for each node, log(N*M) for priority queue
                int r = pq.top().second.first;
                int c = pq.top().second.second;
                int dis = pq.top().first;
                pq.pop();
                if (r == n - 1 && c == m - 1)
                    return dis;
                for (int i = 0; i < 4; i++) { // O(4)
                    int nrow = r + drow[i];
                    int ncol = c + dcol[i];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                        int newEffort =
                            max(abs(heights[nrow][ncol] - heights[r][c]), dis);
                        if(newEffort < dist[nrow][ncol]){
                            dist[nrow][ncol] = newEffort;
                            pq.push({newEffort, {nrow, ncol}});
                        }
                    }
                }
            }
            return 0;
        }
    };