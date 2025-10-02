// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Brute force 

/*#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int totalWater = 0;
    for (int i = 0; i < n; i++) {
        int maxLeft = 0, maxRight = 0;
        
        for (int j = 0; j <= i; j++) {
            maxLeft = max(maxLeft, height[j]);
        }
        
        for (int j = i; j < n; j++) {
            maxRight = max(maxRight, height[j]);
        }
        totalWater += min(maxLeft, maxRight) - height[i];
    }
    return totalWater;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;    
    if (n < 1 || n > 20000) {
        cout << "Invalid array size!" << endl;
        return 1;
    }
    vector<int> height(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        if (height[i] < 0 || height[i] > 100000) {
            cout << "Invalid element value!" << endl;
            return 1;
        }
    }
    int result = trap(height);
    cout << "Trapped Water: " << result << endl;
    return 0;
}*/



// Stack based -- optimized approach

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    stack<int> st;
    int totalWater = 0;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty()) break;
            int left = st.top();
            int width = i - left - 1;
            int boundedHeight = min(height[left], height[i]) - height[top];
            totalWater += width * boundedHeight;
        }
        st.push(i);
    }
    
    return totalWater;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    if (n < 1 || n > 20000) {
        cout << "Invalid array size!" << endl;
        return 1;
    }
    vector<int> height(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        if (height[i] < 0 || height[i] > 100000) {
            cout << "Invalid element value!" << endl;
            return 1;
        }
    }
    int result = trap(height);
    cout << "Trapped Water: " << result << endl;
    return 0;
}