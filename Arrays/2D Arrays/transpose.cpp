#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cout << "Enter the rows and columns: ";
    cin >> n >> m;
    
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    
    vector<vector<int>> transposed(n, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            transposed[j][i] = matrix[i][j];
        }
    }
    
    cout << "Transpose\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << transposed[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
    
}s