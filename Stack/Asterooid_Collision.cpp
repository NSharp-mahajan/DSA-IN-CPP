#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> result = asteroids;
    bool collisionOccurred;
    
    do {
        collisionOccurred = false;
        vector<int> temp;
        int i = 0;
        
        while (i < result.size()) {
            if (i + 1 == result.size() || 
                !(result[i] > 0 && result[i + 1] < 0)) {
                temp.push_back(result[i]);
                i++;
            } else {
                int left = result[i], right = result[i + 1];
                collisionOccurred = true;
                i += 2;
                if (abs(left) > abs(right)) {
                    temp.push_back(left);
                } else if (abs(left) < abs(right)) {
                    temp.push_back(right);
                }
            }
        }
        result = temp;
    } while (collisionOccurred);
    
    return result;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    if (n < 2 || n > 100000) {
        cout << "Invalid array size!" << endl;
        return 1;
    }
    
    vector<int> asteroids(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> asteroids[i];
        if (asteroids[i] == 0 || asteroids[i] < -10000 || asteroids[i] > 10000) {
            cout << "Invalid element value!" << endl;
            return 1;
        }
    }
    
    vector<int> result = asteroidCollision(asteroids);
    cout << "Final Asteroids: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}