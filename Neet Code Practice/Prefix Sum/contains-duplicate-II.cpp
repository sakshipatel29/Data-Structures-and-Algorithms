#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

// Contains Duplicate II

// Logic: Use a set to store the elements and check if the element is already in the set

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_set<int> st;
            for(int i = 0; i < nums.size(); i++){
                if(st.count(nums[i])) return true;
                st.insert(nums[i]);
                if(st.size() > k) st.erase(nums[i-k]);
            }
            return false;
        }
    };