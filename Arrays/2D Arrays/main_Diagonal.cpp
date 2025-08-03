#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of square matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the matrix elements:\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> matrix[i][j];
        }
    }

    cout << "Main Diagonal: ";
    for(int i = 0; i < n; ++i){
        cout << matrix[i][i] << " ";
    }
    return 0;
}
