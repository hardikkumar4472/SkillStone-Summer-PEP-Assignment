#include<bits/stdc++.h>
using namespace std;

int maxMountainSum(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    for (int i = 1; i < n; ++i) {
        if (heights[i] >= heights[i - 1]) {
            left[i] = left[i - 1] + heights[i];
        } else {
            left[i] = heights[i];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        if (heights[i] >= heights[i + 1]) {
            right[i] = right[i + 1] + heights[i];
        } else {
            right[i] = heights[i];
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, left[i] + right[i] - heights[i]);
    }
    return res;
}

int main() {
    vector<int> heights = {100, 50, 60, 70, 60, 50, 100};
    int result = maxMountainSum(heights);
    cout<<result;
    return 0;
}