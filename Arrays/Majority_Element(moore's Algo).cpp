// 1. Majority Element
// ---------- Brute Force Approach -----------------//

/*#include <iostream>
using namespace std;

int majority(int arr[], int n){
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == arr[i]){
                count++;
            }
        }
        if(count > n/2){
            return i;
        };
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    if(n <= 0){
        cout << "Invalid array size" << endl;
        return 0;
    }
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result =majority(arr, n);
    if(result != -1) {
        cout << "The majority element is " << arr[result] << " at index " << result << endl;
    } else {
        cout << "No majority element found" << endl;
    }
    return 0;
}*/

// Optimal Approach ---- Try it on coding ninjas - problem name - Majority Element

/*#include <iostream>
#include <map>
using namespace std;

int findMajorityElement(int arr[], int n) {
	map<int, int>mpp;
	for(int i = 0; i < n; i++){
		mpp[arr[i]]++;
	}
	for(auto it : mpp){
		if(it.second > (n/2)){
			return it.first;
		}
	}
	return -1;
}*/


// Optimal Approach -- Try on leetCode -- Problem no. -- 169

/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int n = nums.size();
        int cnt = 0 , el;

        for(int i = 0 ; i< n ; i++)
        {
            if(cnt == 0) 
            {
                cnt = 1;
                el = nums[i];
            }
            else if (el == nums[i])
            {
                cnt++;
            }
            else{
                cnt--;
            }
        }
 int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) {
                cnt1++;
            }
        }
        if(cnt1 > (n/2))
        {
            return el;
        }
        return -1;
    }
};*/