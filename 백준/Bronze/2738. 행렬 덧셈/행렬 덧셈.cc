#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int** mat1 = new int*[n];
    int** mat2 = new int*[n];
    for (int i = 0; i < n; i++) {
        mat1[i] = new int[m];
        mat2[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat1[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat2[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat1[i][j] += mat2[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat1[i][j] << ' ';
        }
        cout << '\n';
    }
}