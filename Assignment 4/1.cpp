#include <iostream>
#include <string>
using namespace std;

int transform(string A, string B) {
    if (A.length() != B.length()) return -1;
    
    int i = A.length() - 1;
    int j = B.length() - 1;
    int res = 0;
    
    while (i >= 0 && j >= 0) {
        if (A[i] == B[j]) {
            i--;
            j--;
        } else {
            res++;
            i--;
        }
    }
    
    return res;
}

int main() {
    string A = "EACBD";
    string B = "EABCD";
    cout << "Minimum steps to transform: " << transform(A, B) << endl;
    return 0;
}