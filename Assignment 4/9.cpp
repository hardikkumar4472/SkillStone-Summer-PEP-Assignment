#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX, second = INT_MAX;
    for (int num : nums) {
        if (num <= first) {
            first = num;
        } else if (num <= second) {
            second = num;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {5,4,3,2,1};
    
    cout << "Has increasing triplet in nums1: " << boolalpha << increasingTriplet(nums1) << endl;
    cout << "Has increasing triplet in nums2: " << boolalpha << increasingTriplet(nums2) << endl;
    
    return 0;
}