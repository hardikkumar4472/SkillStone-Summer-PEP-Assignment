#include <bits/stdc++.h>
using namespace std;

vector<int> subarrayToSort(vector<int>& arr) {
    int n = arr.size();
    int s = 0;
    int e = n-1;
    
    while (s < n-1 && arr[s] <= arr[s+1]) {
        s++;
    }
    
    if (s == n-1) {
        return {0, 0};
    }
    
    while (e > 0 && arr[e] >= arr[e-1]) {
        e--;
    }
    
    int min_val = *min_element(arr.begin()+s, arr.begin()+e+1);
    int max_val = *max_element(arr.begin()+s, arr.begin()+e+1);
    
    while (s > 0 && arr[s-1] > min_val) {
        s--;
    }
    
    while (e < n-1 && arr[e+1] < max_val) {
        e++;
    }
    
    return {s, e};
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10};
    vector<int> res = subarrayToSort(arr);
    cout << "Subarray to sort from " << res[0] << " to " << res[1];
    return 0;
}