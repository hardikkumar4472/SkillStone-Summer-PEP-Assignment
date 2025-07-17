#include<bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int>& nums) {
    stack<int> st;
    int res = 0;
    for (int num : nums) {
        while (!st.empty() && num > st.top()) {
            st.pop();
        }
        if (!st.empty() && num == st.top()) {
            res += st.size();
        }
        st.push(num);
    }
    return res;
}

int main() {
    vector<int> nums = {1, 4, 2, 3, 4};
    int result = countSubarrays(nums);
    cout<<result;
    return 0;
}