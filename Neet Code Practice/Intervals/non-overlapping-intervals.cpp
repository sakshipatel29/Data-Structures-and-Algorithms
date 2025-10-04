#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//TC: O(NlogN)
//SC: O(N)

class Solution {
    public:
        static bool compare(vector<int>& nums1, vector<int>& nums2){
            return nums1[1] < nums2[1];
        }
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), compare);
            int count = 1;
            int lastEndTime = intervals[0][1];
            for(int i = 1; i < intervals.size(); i++){
                if(intervals[i][0] >= lastEndTime){
                    count++;
                    lastEndTime = intervals[i][1];
                }
            }
            return intervals.size() - count;
        }
    };