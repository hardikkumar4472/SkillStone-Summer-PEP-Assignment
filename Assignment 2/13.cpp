#include <iostream>
using namespace std;

int inSequence(int a, int b, int c) {
    if (c == 0) return a == b ? 1 : 0;
    return (b - a) % c == 0 && (b - a) / c >= 0 ? 1 : 0;
}

int main() {
    int a = 1, b = 7, c = 3;
    cout << "Is present: " << inSequence(a, b, c) << endl;
    return 0;
}