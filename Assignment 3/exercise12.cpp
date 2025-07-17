#include<bits/stdc++.h>
using namespace std;

long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> leftMin(n, -1), rightMin(n, n);
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            leftMin[i] = st.top();
        }
        st.push(i);
    }
    st = stack<int>();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            rightMin[i] = st.top();
        }
        st.push(i);
    }
    long long sumMin = 0;
    for (int i = 0; i < n; ++i) {
        sumMin += (long long)nums[i] * (i - leftMin[i]) * (rightMin[i] - i);
    }
    st = stack<int>();
    vector<int> leftMax(n, -1), rightMax(n, n);
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            leftMax[i] = st.top();
        }
        st.push(i);
    }
    st = stack<int>();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            rightMax[i] = st.top();
        }
        st.push(i);
    }
    long long sumMax = 0;
    for (int i = 0; i < n; ++i) {
        sumMax += (long long)nums[i] * (i - leftMax[i]) * (rightMax[i] - i);
    }
    return sumMax - sumMin;
}

int main() {
    vector<int> nums = {1, 2, 3};
    long long result = subArrayRanges(nums);
    cout<<result;
    return 0;
}