#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> CTS(const vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> sparse;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j]!=0){
                sparse.push_back({i,j,matrix[i][j]});
            }
        }
    }
    return sparse;
}

int main(){
    int n,m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;
    
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter matrix elements: ";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> result = CTS(matrix);
    for(auto row:result){
        cout << row[0] << " " << row[1] << " " << row[2] << endl;
    }
    return 0;
}