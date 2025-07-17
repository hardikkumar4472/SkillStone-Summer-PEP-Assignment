#include<bits/stdc++.h>
using namespace std;

string firstUniqueChar(string s) {
    unordered_map<char, int> freq;
    queue<char> q;
    string res;
    for (char c : s) {
        freq[c]++;
        q.push(c);
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }
        if (q.empty()) {
            res += '#';
        } else {
            res += q.front();
        }
    }
    return res;
}

int main() {
    string s = "aabc";
    string result = firstUniqueChar(s);
    cout<<result;
    return 0;
}