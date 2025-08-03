#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0;
    int col = m-1;
    
    while(row < n && col >= 0){
        if(matrix[row][col] == target){
            return true;
        }else if(matrix[row][col] > target){
            col--;
        }else{
            row++;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {
        {1,  4,  7, 11},
        {2,  5,  8, 12},
        {3,  6,  9, 16},
        {10,13,14,17}
    };
    int target;
    cout << "Enter a target: ";
    cin >> target;
    
    if(searchMatrix(matrix, target)){
        cout << "Target found!" << endl;
    }else{
        cout << "Target not found!" << endl;
    }
    
}