#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int** mat = new int*[n];
    for (int i = 0; i < n; i++)
        mat[i] = new int[m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int input;
            cin >> input;
            mat[i][j] += input;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
}