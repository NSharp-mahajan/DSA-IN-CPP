// 📌 Problem: Print All Divisors of a Number
// 🔸 Given an integer `n`, return all its positive divisors in sorted order.

 
// ⏱ Time Complexity: O(√n)
// 📦 Space Complexity: O(k), where k is the number of divisors

#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int* printDivisors(int n, int &size) {
    set<int> divisors;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.insert(i);
            if (i != n / i) {
                divisors.insert(n / i);
            }
        }
    }
    size = divisors.size();
    int* result = new int[size];

    int idx = 0;
    for (int d : divisors) {
        result[idx++] = d;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int size;
    int* divisors = printDivisors(n, size);

    cout << "Divisors of " << n << ": ";
    for (int i = 0; i < size; i++) {
        cout << divisors[i] << " ";
    }
    cout << endl;
    delete[] divisors;

    return 0;
}
