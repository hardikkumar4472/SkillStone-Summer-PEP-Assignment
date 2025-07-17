#include<bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    int res = 0;
    for (int num : nums) {
        sum = (sum + num) % k;
        if (sum < 0) sum += k;
        res += mp[sum];
        mp[sum]++;
    }
    return res;
}

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    int result = subarraysDivByK(nums, k);
    cout<<result;
    return 0;
}