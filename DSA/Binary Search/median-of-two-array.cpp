// https://leetcode.com/problems/median-of-two-sorted-arrays/
// TC: O(n+m)
// SC: O(n+m)

#include <vector>
#include <iostream>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> nums3;
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(nums1[i] <= nums2[j]){
            nums3.push_back(nums1[i++]);
        }else{
            nums3.push_back(nums2[j++]);
        }
    }
    while(i < n1) nums3.push_back(nums1[i++]);
    while(j < n2) nums3.push_back(nums2[j++]);
    int n = nums3.size();
    double ans = 0;
    if(n%2 == 0){
        return (double)((double)nums3[n/2] + (double)(nums3[(n/2)-1]))/2.0;
    }else{
        return nums3[(n/2)];
    }
    return ans;
}

int main(){
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
}