// TC: O(nlogn+klogn) = O(nlogn)
// SC: O(N)

#include<iostream>
#include <vector>
#include<queue>
using namespace std;

class Solution {
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            vector<vector<int>> ans;
            priority_queue<pair<double, pair<int, int>>,
                            vector<pair<double, pair<int, int>>>,
                            greater<pair<double, pair<int, int>>>>
                pq;
            for (int i = 0; i < points.size(); i++) {
                int x = points[i][0];
                int y = points[i][1];
                double area = sqrt(x * x + y * y);
                pq.push({area, {x, y}});
            }
            while (k > 0) {
                int x = pq.top().second.first;
                int y = pq.top().second.second;
                ans.push_back({x, y});
                pq.pop();
                k--;
            }
            return ans;
        }
    };