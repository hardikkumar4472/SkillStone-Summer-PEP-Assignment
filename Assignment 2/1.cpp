#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& arr1, vector<int>& arr2, int k) {
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end(), greater<int>());
    
    for (int i = 0; i < arr1.size(); ++i) {
        if (arr1[i] + arr2[i] < k) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> arr1 = {2, 1, 3};
    vector<int> arr2 = {7, 8, 9};
    int k = 10;
    
    if (isPossible(arr1, arr2, k)) {
        cout << "Possible" << endl;
    } else {
        cout << "Not Possible" << endl;
    }
    return 0;
}