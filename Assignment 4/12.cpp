#include <iostream>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int countGoodNumbers(long long n) {
    long long evenPos = (n + 1) / 2;
    long long oddPos = n / 2;
    return (power(5, evenPos) * power(4, oddPos)) % MOD;
}

int main() {
    long long n = 4;
    cout << "Good digit strings of length " << n << ": " << countGoodNumbers(n) << endl;
    return 0;
}