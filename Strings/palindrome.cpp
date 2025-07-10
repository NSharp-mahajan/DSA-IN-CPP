// 📌 Problem: Basic Palindrome Check
// ⏱️ Time Complexity: O(n)
// 📦 Space Complexity: O(1)

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string &s)
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    string input = "madam";
    bool result = isPalindrome(input);

    cout << "Is the string a palindrome? ";
    cout << (result ? "Yes ✅" : "No ❌") << endl;

    return 0;
}
