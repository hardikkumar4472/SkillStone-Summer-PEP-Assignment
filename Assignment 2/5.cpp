#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    
    int i = 0, j = 0, k = l, swaps = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            swaps += (m + 1) - (l + i);
        }
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
    return swaps;
}

int mergeSortAndCount(vector<int>& arr, int l, int r) {
    int count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        count += mergeSortAndCount(arr, l, m);
        count += mergeSortAndCount(arr, m + 1, r);
        count += mergeAndCount(arr, l, m, r);
    }
    return count;
}

int main() {
    vector<int> arr = {8, 4, 2, 1};
    cout << "Inversion count: " << mergeSortAndCount(arr, 0, arr.size() - 1) << endl;
    return 0;
}