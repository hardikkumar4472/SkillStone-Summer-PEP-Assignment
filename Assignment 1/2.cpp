#include <bits/stdc++.h>
using namespace std;

int findMinDiff(vector<int>& arr, int m) {
    sort(arr.begin(), arr.end());
    int min_diff = INT_MAX;
    for (int i = 0; i + m - 1 < arr.size(); i++) {
        int current_diff = arr[i+m-1] - arr[i];
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }
    return min_diff;
}

int main() {
    vector<int> arr = {3, 4, 1, 9, 56, 7, 9, 12};
    int m = 5;
    cout << "Minimum difference is " << findMinDiff(arr, m);
    return 0;
}