#include <iostream>
#include<stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string st = "";

        for(char ch : s) {
            if(!st.empty() && st.back() == ch) {
                st.pop_back();
            } 
            else {
                st.push_back(ch); 
            }
        }

        return st;
    }
};

int main() {
    Solution obj;

    string s1 = "abbaca";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << obj.removeDuplicates(s1) << endl;

    string s2 = "azxxzy";
    cout << "\nInput: " << s2 << endl;
    cout << "Output: " << obj.removeDuplicates(s2) << endl;

    return 0;
}
