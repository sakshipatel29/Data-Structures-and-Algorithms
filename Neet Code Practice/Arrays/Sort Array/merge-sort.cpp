#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

// Merge Sort

// Logic: Divide and Conquer

class Solution {
    public:
        void merge(vector<int>& nums, int low, int high, int mid){
            vector<int> temp;
            if(low == high) return;
            int left = low;
            int right = mid + 1;
            while(left <= mid && right <= high){
                if(nums[left] < nums[right]){
                    temp.push_back(nums[left]);
                    left++;
                }else{
                    temp.push_back(nums[right]);
                    right++;
                }
            }
            while(left <= mid){
                temp.push_back(nums[left]);
                left++;
            }
            while(right <= high){
                temp.push_back(nums[right]);
                right++;
            }
            for(int i = low; i <= high; i++){
                nums[i] = temp[i - low];
            }
        }
        void mergeSort(vector<int>& nums, int low, int high){
            if(low >= high) return;
            int mid = (low + high) / 2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid + 1, high);
            merge(nums, low, high, mid);
        }
        vector<int> sortArray(vector<int>& nums) {
            int n = nums.size();
            mergeSort(nums, 0, n-1);
            return nums;
        }
    };