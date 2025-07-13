#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int>& a, vector<int>& b) {
    vector<int> res;
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            if (res.empty() || res.back() != a[i]) {
                res.push_back(a[i]);
            }
            i++;
        } else if (a[i] > b[j]) {
            if (res.empty() || res.back() != b[j]) {
                res.push_back(b[j]);
            }
            j++;
        } else {
            if (res.empty() || res.back() != a[i]) {
                res.push_back(a[i]);
            }
            i++;
            j++;
        }
    }
    while (i < a.size()) {
        if (res.empty() || res.back() != a[i]) {
            res.push_back(a[i]);
        }
        i++;
    }
    while (j < b.size()) {
        if (res.empty() || res.back() != b[j]) {
            res.push_back(b[j]);
        }
        j++;
    }
    return res;
}

int main() {
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 2, 4, 6};
    vector<int> res = findUnion(a, b);
    for (int num : res) {
        cout << num << " ";
    }
    return 0;
}