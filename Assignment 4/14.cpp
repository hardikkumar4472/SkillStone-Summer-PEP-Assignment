#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int eggDrop(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i == 1) {
                dp[i][j] = j;
            } else if (j == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = INT_MAX;
                for (int x = 1; x <= j; x++) {
                    int res = 1 + max(dp[i-1][x-1], dp[i][j-x]);
                    dp[i][j] = min(dp[i][j], res);
                }
            }
        }
    }
    
    return dp[n][k];
}

int main() {
    int eggs = 2;
    int floors = 10;
    cout << "Minimum attempts needed: " << eggDrop(eggs, floors) << endl;
    return 0;
}