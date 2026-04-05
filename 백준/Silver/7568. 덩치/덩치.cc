#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int** human = new int*[n];
    for (int i = 0; i < n; i++)
        human[i] = new int[3];
    for (int i = 0; i < n; i++)
        human[i][2] = 0;

    for (int i = 0; i < n; i++)
        cin >> human[i][0] >> human[i][1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (human[i][0] > human[j][0] && human[i][1] > human[j][1])
                human[j][2]++;
        }
    }

    for (int i = 0; i < n; i++)
        cout << human[i][2] + 1 << ' ';
    cout << '\n';

    for (int i = 0; i < n; i++)
        delete[] human[i];
    delete[] human;
}