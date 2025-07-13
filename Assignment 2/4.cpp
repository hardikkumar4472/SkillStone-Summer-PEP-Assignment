#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool isPossible(vector<int>& arr, int k, int mid) {
    int students = 1, sum = 0;
    for (int page : arr) {
        sum += page;
        if (sum > mid) {
            students++;
            sum = page;
            if (students > k) return false;
        }
    }
    return true;
}

int findPages(vector<int>& arr, int k) {
    if (arr.size() < k) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << "Minimum maximum pages: " << findPages(arr, k) << endl;
    return 0;
}