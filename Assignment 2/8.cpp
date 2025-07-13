#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void sortBySetBitCount(vector<int>& arr) {
    stable_sort(arr.begin(), arr.end(), [](int a, int b) {
        return countSetBits(a) > countSetBits(b);
    });
}

int main() {
    vector<int> arr = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    sortBySetBitCount(arr);
    cout << "Sorted by set bits: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}