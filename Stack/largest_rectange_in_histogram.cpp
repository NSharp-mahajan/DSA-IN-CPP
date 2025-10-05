#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; // Stack to store indices
        int maxArea = 0;
        
        // Iterate through all bars, including a sentinel value
        for (int i = 0; i <= n; i++) {
            // Use heights[n] as 0 to process remaining stack elements
            int currHeight = (i == n) ? 0 : heights[i];
            
            // Pop while stack is not empty and current height is smaller
            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                
                // Width is distance to previous smaller bar
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            
            st.push(i);
        }
        
        return maxArea;
    }
};

int main() {
    int n;
    cout << "Enter the number of bars: ";
    cin >> n;
    
    if (n <= 0 || n > 100000) {
        cout << "Invalid number of bars!" << endl;
        return 1;
    }
    
    vector<int> heights(n);
    cout << "Enter " << n << " heights (0 to 10000): ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        if (heights[i] < 0 || heights[i] > 10000) {
            cout << "Invalid height value!" << endl;
            return 1;
        }
    }
    
    Solution solution;
    int result = solution.largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << result << endl;
    
    return 0;
}