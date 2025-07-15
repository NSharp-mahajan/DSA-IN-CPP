// Problem: Longest Common Prefix
// Given an array of strings, find the longest common prefix (LCP) shared among all strings. If no such prefix exists, return an empty string.

// Time & Space Complexity
// Time Complexity: O(N * M), where
// N = number of strings
// M = length of the shortest string
// Space Complexity: O(1) extra space (excluding output)


#include<iostream>
#include<vector>
using namespace std;

string longest_common_prefix(vector<string>& strs) {
    if(strs.empty()) return "";

    string prefix = "";

    for(int i = 0; i < strs[0].length(); i++) {
        char currentChar = strs[0][i];

        for(int j = 1; j < strs.size(); j++) {
            if (i >= strs[j].length() || strs[j][i] != currentChar) {
                return prefix;
            }
        }

        prefix += currentChar;
    }

    return prefix;
}

int main(){
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter strings: ";
    for(int i = 0; i < n; i++){
        cin >> strs[i];
    }

    string result = longest_common_prefix(strs);
    cout << "Longest common prefix is : " << result << endl;

    return 0;
}
  