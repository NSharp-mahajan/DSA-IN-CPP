// 📌 Problem: Count the Number of Digits in an Integer
// 🔸 Given an integer `n`, return the number of digits it contains.


// ⏱ Time Complexity: O(log₁₀(n))
// 📦 Space Complexity: O(1)

#include <iostream>
using namespace std;

int countDigits(int n) {
    if (n == 0) return 1; // Edge case: 0 has 1 digit

    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Number of digits: " << countDigits(num) << endl;

    return 0;
}
