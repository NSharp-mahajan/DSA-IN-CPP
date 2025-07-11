// 📌 Problem: Check if a Number is Prime
// 🔸 Given a number `n`, determine whether it is a prime number or not.


// ⏱ Time Complexity: O(√n)
// 📦 Space Complexity: O(1)

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;

            // If divisors are not equal, count both
            if ((n / i) != i)
                count++;
        }
    }

    if (count == 2)
        cout << "true";  // Prime
    else
        cout << "false"; // Not Prime

    return 0;
}
