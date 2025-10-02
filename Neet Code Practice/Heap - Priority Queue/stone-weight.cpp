// TC: O(NlogN)
// SC: O(N)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Logic: Use a priority queue to store the stones and pop the two largest stones and push the difference back into the queue

class Solution {
    public:
        int lastStoneWeight(vector<int>& stones) {
            if(stones.size() == 1) return stones[0];
            if(stones.size() == 2) return abs(stones[0] - stones[1]);
            priority_queue<int> pq;
            for(int i = 0; i < stones.size(); i++){
                pq.push(stones[i]);
            }
            while(pq.size() > 1){
                int stone1 = pq.top();
                pq.pop();
                int stone2 = pq.top();
                pq.pop();
    
                if(stone1 == stone2) continue;
                pq.push(abs(stone1 - stone2));
            }
            if(pq.size() == 0) return 0;
            return pq.top();
        }
    };