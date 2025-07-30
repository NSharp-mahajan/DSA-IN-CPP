#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cout << "Enter the number of elements: ";
    cin >> n >> m;

    vector<vector<int>> matrix(n,vector<int>(m));

    cout << "Enter the matrix elements: \n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;  
}