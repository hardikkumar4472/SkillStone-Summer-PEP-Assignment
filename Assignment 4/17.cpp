#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combinationSumHelper(vector<int>& arr, int target, int start, vector<int>& curr, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(curr);
        return;
    }
    
    for (int i = start; i < arr.size() && arr[i] <= target; i++) {
        curr.push_back(arr[i]);
        combinationSumHelper(arr, target - arr[i], i, curr, result);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    vector<int> curr;
    combinationSumHelper(arr, target, 0, curr, result);
    return result;
}

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    
    vector<vector<int>> result = combinationSum(candidates, target);
    cout << "Combination sums:\n";
    for (const auto& comb : result) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}