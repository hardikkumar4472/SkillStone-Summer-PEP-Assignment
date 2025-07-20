#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permuteUniqueHelper(string s, int start, vector<string>& result) {
    if (start == s.length()) {
        result.push_back(s);
        return;
    }
    
    for (int i = start; i < s.length(); i++) {
        if (i != start && s[i] == s[start]) continue;
        swap(s[start], s[i]);
        permuteUniqueHelper(s, start + 1, result);
    }
}

vector<string> permuteUnique(string s) {
    vector<string> result;
    sort(s.begin(), s.end());
    permuteUniqueHelper(s, 0, result);
    return result;
}

int main() {
    string s = "AAB";
    vector<string> permutations = permuteUnique(s);
    
    cout << "Unique permutations:\n";
    for (const string& perm : permutations) {
        cout << perm << endl;
    }
    
    return 0;
}