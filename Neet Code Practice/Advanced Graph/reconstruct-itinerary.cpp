//TC: O(NLOGN)
//SC: O(N)

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        void dfs(string airport, unordered_map<string, vector<string>> &adj, vector<string> &ans){
            auto &dest = adj[airport];
            while(!dest.empty()){
                string next = dest.back();
                dest.pop_back();
                dfs(next, adj, ans);
            }
            ans.push_back(airport);  
        }
        vector<string> findItinerary(vector<vector<string>>& tickets) {
            int n = tickets.size();
            unordered_map<string, vector<string>> adj;
            for(auto ticket : tickets){
                adj[ticket[0]].push_back(ticket[1]);
            }
            for(auto& temp : adj){
                sort(temp.second.rbegin(), temp.second.rend());
            }
            vector<string> ans;
            string jfk = "JFK";
            dfs(jfk, adj, ans);
    
            reverse(ans.begin(), ans.end());
    
            return ans;
    
        }
    };