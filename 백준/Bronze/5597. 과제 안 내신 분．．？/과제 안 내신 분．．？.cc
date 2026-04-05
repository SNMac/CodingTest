#include <iostream>

using namespace std;

int main() {
    int students[31];
    fill_n(students, 31, 0);
    int num;
    for (int i = 0; i < 28; i++) {
        cin >> num;
        students[num] = num;
    }
    int min = 30, max = 1;
    for (int i = 1; i <= 30; i++) {
        if (students[i] == 0) {
            if (i > max)
                max = i;
            if (i < min)
                min = i;
        }
    }
    cout << min << '\n' << max << '\n';
}