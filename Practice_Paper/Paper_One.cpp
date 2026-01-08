/*Q1. Family Photograph:

N members of a family are lined up in the increasing order of their heights for a family photograph. But to click a better snap, the photographer decided to reverse their positions in the groups of k members each.

Given an array and an integer k, where each array element denotes the height of a person standing at the respective position originally. Your task is to print their heights according to their final position, after reversing in the groups of k.

For example, If the height's array is {1, 2, 3, 4, 5, 6, 7, 8, 9}, i.e. denoting the original positions of the family members, and k = 3, then their final positions should be {3, 2, 1, 6, 5, 4, 9, 8, 7}, i.e. after reversing them in the groups of 3 members each.

Note: The last group on the right side may contain less than k members.
*/

/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);

    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    int K;
    cin >> K;
    for(int i = 0; i < N; i+= K){
        int end = i + K - 1;
        if(end >= N){
            end = N-1;
        }
        reverse(a.begin()+i, a.begin()+ end + 1);
    }
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    return 0;
}*/

// Q2. Airport Mishap 

/*You are working as a software engineer for an airline's baggage tracking system. Before a flight takes off, every piece of luggage is scanned and its unique ID(nonnegative integers) is recorded in a database. During the flight, the luggage shifts around in the cargo hold, changing the order.

Upon landing, the ground crew scans the bags as they are unloaded onto the conveyor belt. However, the crew realizes that the number of bags unloaded is one less than the number of bags loaded. One bag has been lost in transit! Given the list of bag IDs at departure and the scrambled list of bag IDs at arrival, your task is to identify the ID of the missing bag.*/

/*#include<iostream>
#include<vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int m,n;
        cin >> m >> n;
        vector<int>dep(m), arr(n);
        int sumDep = 0, sumArr = 0;
        for(int i = 0; i < m; i++){
            cin >> dep[i];
            sumDep += dep[i];
        }
        for(int i = 0; i < n;i++){
            cin >> arr[i];
            sumArr += arr[i];
        }
        cout << (sumDep - sumArr) << endl;
    }
    return 0;
}*/

/*Q3. Upper Triangular Matrix Verification
Imagine you are a Quality Control (QC) Inspector at a factory that produces specialized mathematical objects called Square Matrices.

Your current job is to take a batch of these matrices and check if they meet a specific design requirement: Are they an Upper Triangular Matrix?

The Rule for an Upper Triangular Matrix

--For a matrix to be approved as "Upper Triangular," every single component (element) that is located below the main diagonal must be a zero (0).

--The main diagonal runs from the top-left corner down to the bottom-right corner.

Your Task as the QC Inspector:

--Display the Matrix: First, you must clearly present the contents of the matrix you are inspecting so everyone can see it.

--Give the Verdict: After checking all the elements below the main diagonal against the rule (must be zero), you must then display a final, clear message stating:

--"not an upper triangular matrix" OR
--"upper triangular matrix"*/

/*#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[5][5];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
    }
    bool isUpper = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; i < i; i++){
            isUpper = false;
            break;
        }
    }
    if(isUpper){
        cout << "is an UTM" << endl;
    }else{
        cout << "Not a UTM" << endl;
    }

}*/

// Q4. The magic card Game -- proper postfix expression

/*#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
using namespace std;

int applyOp(int a, int b, char op){
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a,b);
    }
    return 0;
}

int evalPostFix(string exp){
    stack<int> st;
    for(char ch: exp){
        if(isdigit(ch)){
            st.push(ch-'0');
        }else{
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            int result = applyOp(val1, val2, ch);
            st.push(result);
        }
    }
    return st.top();
}
int main() {
    int T;
    cin >> T;

    while (T--) {
        string exp;
        cin >> exp;

        int result = evalPostFix(exp);
        cout << result << endl;
    }

    return 0;
}*/

/*Q5. The Cafeteria Tray Dispenser


You are in charge of the tray dispenser in a busy cafeteria. The dispenser operates on a strict "Last In, First Out" basis. Because the mechanism is old, you track the trays using a dynamic list where every tray is physically linked to the one below it.

You receive a series of instructions from the kitchen manager:

1. Instruction Type 1 (Restock): The dishwasher brings a clean tray with a specific ID number and places it on top of the stack.

2. Instruction Type 2 (Serve): A customer arrives to eat. You must remove the tray currently at the very top of the stack and hand it to them (print the 
tray ID).

If a customer asks for a tray but the dispenser is completely empty, you must signal that no trays are available by reporting -1
*/

/*#include<iostream>
#include<stack>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){ 
        stack<int>st;
        int Q;
        cin >> Q;
        while(Q--){
            int type;
            cin >> type;
            
            if(type == 1){
                int trayId;
                cin >> trayId;
                st.push(trayId);
            }
            else if(type ==2){
                if(st.empty()){
                    cout << -1 << " ";
                }else{
                    cout << st.top() << endl;
                    st.pop();
                }
            }
        }
        cout << endl;
    }
    return 0;
}*/

// Q6. Action first math Processor - prefix code

/*#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

int applyOp(int a, int b, char op){
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;  
        case '^': return pow(a, b);
    }
    return 0;
}

int evalPrefix(string exp){
    stack<int>st;
    for(int i = exp.length() - 1; i >= 0; i--){
        char ch = exp[i];
        if(isdigit(ch)){
            st.push(ch-'0');
        }
        else{
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            int result = applyOp(a, b, ch);
            st.push(result);
        }
    }
    return st.top();
}
int main() {
    int T;
    cin >> T;

    while (T--) {
        string exp;
        cin >> exp;
        cout << evalPrefix(exp) << endl;
    }
    return 0;
}*/

/* Q7. Duplicate Flyer Detection


In a busy international airport, passenger IDs are logged every time a traveler passes through a security checkpoint. However, due to repeat scans or additional checks, the same flyer may be logged more than once.

Your have to help the airport system identify all duplicate flyer IDs — those that appear more than once in the scanned log.*/

/*#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<string,int>freq;
    vector<string> ids(n);

    for(int i = 0; i < n; i++){
        cin >> ids[i];
        freq[ids[i]]++;
    }
    for(auto &p: freq){
        if(p.second > 1){
            cout << p.first << endl;
        }
    }
    return 0;
}*/

/*Q8. Brand Logo of a company


A couple decided to open a footwear company, and for its brand logo they wanted to use a single letter. So, they thought of a very interesting method, i.e. any letter from the wife's name that is present at the minimum index in the husband's name will be selected as their company's logo, and if no letter of wife's name is present in husband's name then they will choose letter 'h'.

Now, given the name of both husband and wife, you have to find the logo for their company as per the above method. For example, given husband's name =
"nimish" and wife's name = "seema", then two characters (s and m) appears in husband's name, but we will choose 'm' as their company's logo because it appears at minimum index.
*/

/*#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        string husband, wife;
        cin >> husband >> wife;
        unordered_set<char>wifeSet(wife.begin(), wife.end());
        char logo = 'h';
        bool found = false;
        for(char ch : husband){
            if(wifeSet.count(ch) == 1){
                logo = ch;
                found = true;
                break;
            }
        }
        cout << endl;
    }
    return 0;
}*/

/*Q9. Decode Enemy Message:


Turing intercepts an encoded message from the enemy country, and he has cracked the logic to decode that. The decoding logic is as follows:
The encoded string is composed of multiple words which are separated by space, and to decode that, one needs to reverse the words in the string individually, not the whole string.

Turing needs your help in writing an algorithm to decode those intercepted messages.

Complete the function decodeMessage() which takes the string as parameter and reverse the individual words of string and returns it.*/


#include <iostream>
#include <algorithm>
using namespace std;

string decodeMessage(string s) {
    string result = "";
    string word = "";

    for (char ch : s) {
        if (ch == ' ') {
            // reverse the collected word
            reverse(word.begin(), word.end());
            result += word + " ";
            word = ""; // reset for next word
        }
        else {
            word += ch;
        }
    }

    // reverse the last word
    reverse(word.begin(), word.end());
    result += word;

    return result;
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); 

    while (N--) {
        string msg;
        getline(cin, msg);

        cout << decodeMessage(msg) << endl;
    }

    return 0;
}