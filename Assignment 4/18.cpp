#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) return false;
    }
    return true;
}

void partitionHelper(string s, int start, vector<string>& curr, vector<vector<string>>& result) {
    if (start == s.length()) {
        result.push_back(curr);
        return;
    }
    
    for (int i = start; i < s.length(); i++) {
        if (isPalindrome(s, start, i)) {
            curr.push_back(s.substr(start, i - start + 1));
            partitionHelper(s, i + 1, curr, result);
            curr.pop_back();
        }
    }
}

vector<vector<string>> allPalindromicPerms(string S) {
    vector<vector<string>> result;
    vector<string> curr;
    partitionHelper(S, 0, curr, result);
    return result;
}

int main() {
    string s = "aab";
    vector<vector<string>> partitions = allPalindromicPerms(s);
    
    cout << "Palindromic partitions:\n";
    for (const auto& part : partitions) {
        for (const string& str : part) {
            cout << str << " ";
        }
        cout << endl;
    }
    
    return 0;
}