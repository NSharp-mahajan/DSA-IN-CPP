// Brute force approach 

/*#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    long long maxArea = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long area = (long long)min(height[i], height[j]) * (j - i);
            maxArea = max(maxArea, area);
        }
    }
    
    return maxArea;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    if (n < 2 || n > 100000) {
        cout << "Invalid array size!" << endl;
        return 1;
    }
    
    vector<int> height(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        if (height[i] < 0 || height[i] > 10000) {
            cout << "Invalid element value!" << endl;
            return 1;
        }
    }
    
    int result = maxArea(height);
    cout << "Maximum Water Area: " << result << endl;
    
    return 0;
}*/

// Optimized approach

#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;
    long long maxArea = 0;
    
    while (left < right) {
        long long area = (long long)min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, area);
        
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return maxArea;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    if (n < 2 || n > 100000) {
        cout << "Invalid array size!" << endl;
        return 1;
    }
    
    vector<int> height(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        if (height[i] < 0 || height[i] > 10000) {
            cout << "Invalid element value!" << endl;
            return 1;
        }
    }
    
    int result = maxArea(height);
    cout << "Maximum Water Area: " << result << endl;
    
    return 0;
}