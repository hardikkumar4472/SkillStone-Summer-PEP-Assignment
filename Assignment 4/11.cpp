#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

string decodeString(string s) {
    stack<string> chars;
    stack<int> nums;
    string curr;
    int num = 0;
    
    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (isalpha(c)) {
            curr += c;
        } else if (c == '[') {
            chars.push(curr);
            nums.push(num);
            curr = "";
            num = 0;
        } else if (c == ']') {
            string temp = curr;
            curr = chars.top();
            chars.pop();
            int repeat = nums.top();
            nums.pop();
            while (repeat-- > 0) {
                curr += temp;
            }
        }
    }
    
    return curr;
}

int main() {
    string s1 = "3[a]2[bc]";
    string s2 = "3[a2[c]]";
    
    cout << "Decoded string 1: " << decodeString(s1) << endl;
    cout << "Decoded string 2: " << decodeString(s2) << endl;
    
    return 0;
}