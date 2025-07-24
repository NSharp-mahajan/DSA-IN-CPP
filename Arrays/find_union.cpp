// 📌 Problem: Merge Two Sorted Arrays Without Duplicates (Brute Force)
// 🔹 Given two sorted arrays, merge them into one sorted array without duplicates.

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> mergeSortedArrays(vector<int> a, vector<int> b) {
    set<int> st;
    for (int i = 0; i < a.size(); i++) {
        st.insert(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        st.insert(b[i]);
    }
    vector<int> result;
    for (auto it : st) {
        result.push_back(it);
    }

    return result;
}

int main() {
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    vector<int> a(n1);
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < n1; i++) cin >> a[i];

    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> b(n2);
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < n2; i++) cin >> b[i];

    vector<int> merged = mergeSortedArrays(a, b);

    cout << "Merged sorted array without duplicates: ";
    for (int x : merged) cout << x << " ";
    cout << endl;

    return 0;
}

// ~ Written by Natansh Mahajan

// ⚠️ NOTE: This is a brute-force approach using set (O(n log n))
// ✅ For an optimal solution using two pointers and O(n + m) time, check it out on LeetCode (https://leetcode.com/u/Natansh_n20/)
