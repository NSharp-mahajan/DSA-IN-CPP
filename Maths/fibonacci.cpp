// 📌 Problem: Nth Fibonacci Number
// 🔸 Given an integer `n`, return the nth Fibonacci number.
// 🔸 The Fibonacci sequence is: 0, 1, 1, 2, 3, 5, 8, 13, ...

// 💡 Approach:
// 🔹 Use an iterative method with 3 variables: prev2, prev1, and curr.

// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1)

#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev2 = 0, prev1 = 1, curr;

    for (int i = 2; i <= n; i++) {
        curr = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " is: " << fib(n) << endl;

    return 0;
}
