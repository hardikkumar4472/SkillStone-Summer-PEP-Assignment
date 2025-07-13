#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& chefs, int n, long long time) {
    long long donuts = 0;
    for (int r : chefs) {
        long long low = 0, high = 1e9;
        long long max_d = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid * (mid + 1) / 2 * r <= time) {
                max_d = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        donuts += max_d;
        if (donuts >= n) return true;
    }
    return donuts >= n;
}

long long minTime(vector<int>& chefs, int n) {
    long long left = 0;
    long long right = *max_element(chefs.begin(), chefs.end()) * (long long)n * (n + 1) / 2;
    long long result = right;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (isPossible(chefs, n, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> chefs = {1, 2, 3};
    int n = 11;
    cout << "Minimum time: " << minTime(chefs, n) << endl;
    return 0;
}