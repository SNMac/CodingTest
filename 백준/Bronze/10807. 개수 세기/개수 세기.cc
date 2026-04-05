#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int findNum, count = 0;
    cin >> findNum;
    for (int i = 0; i < n; i++) {
        if (arr[i] == findNum)
            count++;
    }
    cout << count << '\n';
}