#include <bits/stdc++.h>
using namespace std;

int maxLenZeroSum(vector<int>& arr) {
    unordered_map<int, int> map;
    int max_len = 0;
    int sum = 0;
    map[0] = -1;
    
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (map.find(sum) != map.end()) {
            max_len = max(max_len, i - map[sum]);
        } else {
            map[sum] = i;
        }
    }
    return max_len;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << "Length of largest subarray with 0 sum: " << maxLenZeroSum(arr);
    return 0;
}