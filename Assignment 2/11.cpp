#include <iostream>
#include <vector>
using namespace std;

int searchStepArray(vector<int>& arr, int k, int x) {
    int i = 0;
    while (i < arr.size()) {
        if (arr[i] == x) return i;
        i += max(1, abs(arr[i] - x) / k);
    }
    return -1;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 6};
    int k = 1, x = 6;
    cout << "Element found at index: " << searchStepArray(arr, k, x) << endl;
    return 0;
}