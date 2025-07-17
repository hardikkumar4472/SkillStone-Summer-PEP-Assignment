#include<bits/stdc++.h>
using namespace std;

int countSubstrings(string str) {
    map<pair<int, int>, int> mp;
    mp[{0, 0}] = 1;
    int c0 = 0, c1 = 0, c2 = 0;
    int res = 0;
    for (char c : str) {
        if (c == '0') c0++;
        else if (c == '1') c1++;
        else c2++;
        pair<int, int> key = {c1 - c0, c2 - c1};
        res += mp[key];
        mp[key]++;
    }
    return res;
}

int main() {
    string str = "0102010";
    int result = countSubstrings(str);
    cout<<result;
    return 0;
}