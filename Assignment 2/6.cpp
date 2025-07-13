#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& stalls, int c, int mid) {
    int cows = 1, last = stalls[0];
    for (int stall : stalls) {
        if (stall - last >= mid) {
            cows++;
            last = stall;
            if (cows == c) return true;
        }
    }
    return false;
}

int largestMinDistance(vector<int>& stalls, int c) {
    sort(stalls.begin(), stalls.end());
    int low = 0, high = stalls.back() - stalls.front();
    int result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(stalls, c, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int c = 3;
    cout << "Largest minimum distance: " << largestMinDistance(stalls, c) << endl;
    return 0;
}