#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int>& arr, int k) {
    for (int i = 0; i < k; i++) {
        int min_idx = i;
        for (int j = i+1; j < arr.size(); j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
    return arr[k-1];
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "Kth smallest element is " << kthSmallest(arr, k);
    return 0;
}