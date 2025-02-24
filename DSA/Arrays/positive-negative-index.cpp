//TC: O(N)
//SC: O(N)

#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    int leftPointer = 1;
    int rightPointer = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] < 0) {
            ans[leftPointer] = nums[i];
            leftPointer += 2;
        } else {
            ans[rightPointer] = nums[i];
            rightPointer += 2;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = rearrangeArray(arr);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
