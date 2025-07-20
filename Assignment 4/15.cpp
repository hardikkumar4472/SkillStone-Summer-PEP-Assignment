#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int smallestSubarraySum(vector<int>& arr, int n) {
    int min_ending_here = INT_MAX;
    int min_so_far = INT_MAX;
    
    for (int num : arr) {
        if (min_ending_here > 0) {
            min_ending_here = num;
        } else {
            min_ending_here += num;
        }
        min_so_far = min(min_so_far, min_ending_here);
    }
    
    return min_so_far;
}

int main() {
    vector<int> arr = {3, -4, 2, -3, -1, 7, -5};
    cout << "Minimum subarray sum: " << smallestSubarraySum(arr, arr.size()) << endl;
    return 0;
}