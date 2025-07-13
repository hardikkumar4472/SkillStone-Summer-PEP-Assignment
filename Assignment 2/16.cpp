#include <iostream>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int countNumbers(int n, int d) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (i - digitSum(i) >= d) {
            count++;
        }
    }
    return count;
}

int main() {
    int n = 20, d = 5;
    cout << "Count: " << countNumbers(n, d) << endl;
    return 0;
}