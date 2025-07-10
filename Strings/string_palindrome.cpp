// 🔸 Check if a given string is a palindrome,

// 💡 Approach:
// 🔹 Use two pointers (left and right)
// 🔹 Skip non-alphanumeric characters using isalnum()
// 🔹 Compare lowercase versions of characters using tolower()

// ⏱️ Time Complexity: O(n)
// 📦 Space Complexity: O(1) (ignoring input string size)

#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string s)
{
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;

        if (tolower(s[left]) != tolower(s[right]))
            return false;

        left++;
        right--;
    }

    return true;
}

int main() {
    string input = "A man, a plan, a canal: Panama";
    bool result = checkPalindrome(input);

    cout << "Is the string a valid palindrome? ";
    cout << (result ? "Yes ✅" : "No ❌") << endl;

    return 0;
}
