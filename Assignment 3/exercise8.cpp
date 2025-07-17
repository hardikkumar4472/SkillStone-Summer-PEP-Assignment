#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < arr.size(); ++i) {
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (dq.front() == i - k) {
            dq.pop_front();
        }
        if (i >= k - 1) {
            res.push_back(arr[dq.front()]);
        }
    }
    return res;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(arr, k);
    for (int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}