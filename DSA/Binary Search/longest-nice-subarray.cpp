// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int longestNiceSubarray(vector<int>& nums) {
    int n = nums.size();
    int max_length = 1;
    int left = 0;
    int used_bits = 0;
    
    for (int right = 0; right < n; ++right) {
        while ((used_bits & nums[right]) != 0) {
            used_bits ^= nums[left];
            ++left;
        }
        used_bits |= nums[right];
        max_length = max(max_length, right - left + 1);
    }
    return max_length;
}

int main(){
    vector<int> nums = {1,3,8,48,10};
    cout << longestNiceSubarray(nums) << endl;
    return 0;
}