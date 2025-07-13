#include <iostream>
using namespace std;

int findKthNumber(int m, int n, int k) {
    int left = 1, right = m * n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = 0;
        
        for (int i = 1; i <= m; ++i) {
            count += min(mid / i, n);
        }
        
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int m = 3, n = 3, k = 5;
    cout << "Kth smallest: " << findKthNumber(m, n, k) << endl;
    return 0;
}