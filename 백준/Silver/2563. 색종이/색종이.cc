#include <iostream>

using namespace std;

int main() {
    bool papers[100][100];
    for (int i = 0; i < 100; i++)
        fill_n(papers[i], 100, false);
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int k = 0; k < 10; k++) {
            for (int l = 0; l < 10; l++) {
                papers[x + k][y + l] = true;
            }
        }
    }

    int area = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (papers[i][j])
                area++;
        }
    }
    cout << area << '\n';
}