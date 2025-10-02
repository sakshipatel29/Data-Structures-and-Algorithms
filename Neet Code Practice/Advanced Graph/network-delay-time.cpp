#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TC: O(N*M)
// SC: O(N*M)

class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            vector<vector<pair<int, int>>> adj(n+1);
            for(auto time : times){
                adj[time[0]].push_back({time[1], time[2]});
            }
            vector<int> dist(n+1, 1e9);
            dist[k] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, k});
            while(!pq.empty()){
                int time = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                for(auto it : adj[node]){
                    if(dist[it.first] > time + it.second){
                        dist[it.first] = time + it.second;
                        pq.push({time + it.second, it.first});
                    }
                }
            }
            int maxi = 0;
            for(int i = 1; i < n + 1; i++){
                if(dist[i] == 1e9) return -1;
                maxi = max(maxi, dist[i]);
            }
            return maxi;
        }
    };