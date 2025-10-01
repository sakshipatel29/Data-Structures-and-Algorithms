#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//TC: O(NlogK)
//SC: O(K)
class KthLargest {
    public:
        int k;
        priority_queue<int, vector<int>, greater<int>> pq;
        KthLargest(int k, vector<int>& nums) {
            this->k = k;
            for(int i = 0; i < nums.size(); i++){
                add(nums[i]);
            }
        }
        
        int add(int val) {
            if(pq.size() < k || pq.top() < val){
                pq.push(val);
                if(pq.size() > k){
                    pq.pop();
                }
            }
            return pq.top();
        }
    };