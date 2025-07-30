#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Column-wise Traversal:\n";
    for (int j = 0; j < m; ++j) {           
        for (int i = 0; i < n; ++i) {       
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
