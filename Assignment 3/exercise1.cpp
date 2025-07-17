#include<bits/stdc++.h>
using namespace std;

int totalStrength(vector<int>& strength) {
    const int MOD = 1e9 + 7;
    int n = strength.size();
    vector<long long> prefix(n + 2, 0);
    vector<long long> prefixPrefix(n + 2, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = (prefix[i] + strength[i]) % MOD;
    }
    for (int i = 0; i <= n; ++i) {
        prefixPrefix[i + 1] = (prefixPrefix[i] + prefix[i]) % MOD;
    }
    stack<int> st;
    vector<int> left(n, -1);
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && strength[st.top()] >= strength[i]) {
            st.pop();
        }
        if (!st.empty()) {
            left[i] = st.top();
        }
        st.push(i);
    }
    st = stack<int>();
    vector<int> right(n, n);
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && strength[st.top()] > strength[i]) {
            st.pop();
        }
        if (!st.empty()) {
            right[i] = st.top();
        }
        st.push(i);
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        int l = left[i] + 1;
        int r = right[i] - 1;
        long long total = (prefixPrefix[r + 2] - prefixPrefix[i + 1]) * (i - l + 1) % MOD;
        total = (total - (prefixPrefix[i + 1] - prefixPrefix[l]) * (r - i + 1) % MOD + MOD) % MOD;
        res = (res + strength[i] * total) % MOD;
    }
    return res;
}

int main() {
    vector<int> strength = {1, 3, 1, 2};
    int result = totalStrength(strength);
    cout<<result;
    return 0;
}