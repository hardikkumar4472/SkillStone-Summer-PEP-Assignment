#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupStrings(vector<string>& strings) {
    unordered_map<string, vector<string>> mp;
    for (string s : strings) {
        string key;
        for (int i = 1; i < s.size(); ++i) {
            int diff = s[i] - s[i - 1];
            if (diff < 0) diff += 26;
            key += to_string(diff) + ",";
        }
        mp[key].push_back(s);
    }
    vector<vector<string>> res;
    for (auto it : mp) {
        res.push_back(it.second);
    }
    return res;
}

int main() {
    vector<string> strings = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    vector<vector<string>> result = groupStrings(strings);
    return 0;
}