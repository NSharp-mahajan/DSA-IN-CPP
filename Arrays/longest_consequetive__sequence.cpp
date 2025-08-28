#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    if (n == 0) return 0;

    sort(arr.begin(), arr.end());

    int last_smaller = INT_MIN;
    int count = 0;
    int longest = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] - 1 == last_smaller) {
            count += 1;
            last_smaller = arr[i];
        } 
        else if (arr[i] != last_smaller) {
            count = 1;
            last_smaller = arr[i];
        }

        longest = max(longest, count);
    }

    return longest;
}

int main() {
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    int n = arr.size();

    cout << lengthOfLongestConsecutiveSequence(arr, n) << endl; 
    return 0;
}
