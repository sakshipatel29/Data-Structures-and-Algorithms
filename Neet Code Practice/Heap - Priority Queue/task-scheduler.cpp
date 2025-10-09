//T = number of tasks (tasks.size()).
//K = number of unique task types.
// TC: O(TlogK) // K is constant so nearly O(T)
// SC: O(K + N) // N and K constant so nearly O(1)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            unordered_map<char, int> mpp;
            for(auto ch : tasks){
                mpp[ch]++;
            }
            priority_queue<int> pq;
            for(auto it : mpp){
                pq.push(it.second);
            }
            int count = 0;
            while(!pq.empty()){
                vector<int>temp;
                int len = n + 1;
    
                for(int i = 0; i < len; i++){
                    if(!pq.empty()){
                        int element = pq.top();
                        pq.pop();
                        element--;
                        temp.push_back(element);
                    }
                }
                for(int &i : temp){
                    if(i > 0) pq.push(i);
                }
    
                if(pq.empty()) count += temp.size();
                else count += (n+1);
            }
            return count;
        }
    };