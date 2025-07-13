#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwaps(vector<int>& arr) {
    vector<pair<int, int>> arrPos;
    for (int i = 0; i < arr.size(); i++) {
        arrPos.emplace_back(arr[i], i);
    }
    
    sort(arrPos.begin(), arrPos.end());
    vector<bool> visited(arr.size(), false);
    int swaps = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        if (visited[i] || arrPos[i].second == i) continue;
        
        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = arrPos[j].second;
            cycle_size++;
        }
        
        if (cycle_size > 0) {
            swaps += (cycle_size - 1);
        }
    }
    return swaps;
}

int main() {
    vector<int> arr = {4, 3, 2, 1};
    cout << "Minimum swaps: " << minSwaps(arr) << endl;
    return 0;
}