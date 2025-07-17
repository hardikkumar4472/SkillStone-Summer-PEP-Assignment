#include<bits/stdc++.h>
using namespace std;

int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();
    int left = k, right = k;
    int min_val = nums[k];
    int res = min_val;
    while (left > 0 || right < n - 1) {
        if (left == 0 || (right < n - 1 && nums[right + 1] > nums[left - 1])) {
            right++;
        } else {
            left--;
        }
        min_val = min(min_val, min(nums[left], nums[right]));
        res = max(res, min_val * (right - left + 1));
    }
    return res;
}

int main() {
    vector<int> nums = {1, 4, 3, 7, 4, 5};
    int k = 3;
    int result = maximumScore(nums, k);
    cout<<result;
    return 0;
}