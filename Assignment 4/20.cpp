#include <iostream>
#include <vector>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> inDegree(n + 1, 0);
    vector<int> outDegree(n + 1, 0);
    
    for (const auto& t : trust) {
        outDegree[t[0]]++;
        inDegree[t[1]]++;
    }
    
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == n - 1 && outDegree[i] == 0) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    int n = 4;
    vector<vector<int>> trust = {{1,3}, {1,4}, {2,3}, {2,4}, {4,3}};
    
    int judge = findJudge(n, trust);
    if (judge != -1) {
        cout << "Town judge is: " << judge << endl;
    } else {
        cout << "No town judge found" << endl;
    }
    
    return 0;
}