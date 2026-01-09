/* Q1. The VIP Reversal at the Ice Cream Truck:
Imagine a very popular ice cream truck, "The Sweet Stop." Customers line up in a Queue—the first person in line gets the next ice cream.

Concept: Changing the order of the line so the person who arrived last gets served first. */

/*#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reversequeue(queue<int> &q){
    stack<int>st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        queue<int> q;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            q.push(x);
        }
        reversequeue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
    return 0;
}*/

// Q2. Predicting Demand Drops in Inventory Management:

/*Imagine you are an inventory manager at a warehouse that stores various products with fluctuating demand. You have a list of product
demand levels recorded over several days, and you need to analyze market trends to optimize stock levels. For each day's demand, you
want to determine when the demand will next decrease in the upcoming days.

You have n days of demand data stored in an array demand[ ], where demand[i] represents the demand for a product on the i-th day. Your
task is to find the next day (to the right) when the demand is lower than the current day's demand. If no such lower demand exists in the upcoming days, print -1 for that day.*/

/*#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerToRight(vector<int>& arr, int n) {
    stack<int> st;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }

        st.push(arr[i]);
    }

    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<int> result = nextSmallerToRight(arr, n);
        for (int i = 0; i < n; i++) {
            cout << result[i];
            if (i != n - 1) cout << " ";  
        }
        cout << endl;
    }

    return 0;
}*/

// Valid Parenthesis 

/*#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string &s) {
    stack<char> st;

    for (char ch : s) {

        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // For closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {

            // If stack empty → no matching opening
            if (st.empty()) {
                return false;
            }

            char top = st.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); 

    while (T--) {
        string code;
        getline(cin, code);

        if (isBalanced(code)) {
            cout << "Success" << endl;
        } else {
            cout << "Error" << endl;
        }
    }

    return 0;
}*/

/*Q4. Cinema Seat Booking System:


A cinema hall has its seating arrangement represented as a 2D array of size R × C (rows × columns).

--Each element in the array represents a seat:

0 → Empty seat
1 → Booked seat

--A group of friends wants to book K consecutive seats in the same row.

--Write a program to find if there exists at least one block of K consecutive empty seats in any row.
*/

/*#include <iostream>
#include <vector>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> seats(R, vector<int>(C));

    // Read the seating layout
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> seats[i][j];
        }
    }

    int K;
    cin >> K;

    bool found = false;
    int finalRow = -1, finalCol = -1;

    // Check each row for K empty seats
    for (int i = 0; i < R; i++) {

        int consecutive = 0;       // how many empty seats found in a row
        int startCol = 0;          // start of the empty block

        for (int j = 0; j < C; j++) {

            if (seats[i][j] == 0) {
                if (consecutive == 0) {
                    startCol = j;
                }

                consecutive++;
                if (consecutive == K) {
                    found = true;
                    finalRow = i + 1;   
                    finalCol = startCol + 1;
                    break;
                }
            }
            else {
                consecutive = 0;
            }
        }

        if (found) break;
    }

    if (found) {
        cout << "Available at Row " << finalRow
             << ", Starting Column " << finalCol;
    } else {
        cout << "Not Available";
    }

    return 0;
} */                                         