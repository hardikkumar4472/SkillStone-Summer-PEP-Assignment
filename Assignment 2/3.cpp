#include <iostream>
#include <vector>
using namespace std;

int kthElement(vector<int>& a, vector<int>& b, int k) {
    int i = 0, j = 0, count = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            if (++count == k) return a[i];
            i++;
        } else {
            if (++count == k) return b[j];
            j++;
        }
    }
    while (i < a.size()) {
        if (++count == k) return a[i];
        i++;
    }
    while (j < b.size()) {
        if (++count == k) return b[j];
        j++;
    }
    return -1;
}

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    cout << "Kth element: " << kthElement(a, b, k) << endl;
    return 0;
}