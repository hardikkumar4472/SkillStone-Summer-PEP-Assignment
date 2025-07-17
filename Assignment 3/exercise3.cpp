#include<bits/stdc++.h>
using namespace std;

int totalSteps(vector<int>& nums) {
    int n = nums.size();
    stack<pair<int, int>> st;
    int res = 0;
    for (int i = n - 1; i >= 0; --i) {
        int steps = 0;
        while (!st.empty() && nums[i] > st.top().first) {
            steps = max(steps + 1, st.top().second);
            st.pop();
        }
        res = max(res, steps);
        st.push({nums[i], steps});
    }
    return res;
}

int main() {
    vector<int> nums = {5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11};
    int result = totalSteps(nums);
    cout<<result;
    return 0;
}