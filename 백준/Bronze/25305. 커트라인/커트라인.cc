#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int* students = new int[n];
    for (int i = 0; i < n; i++)
        cin >> students[i];
    
    sort(students, students + n);
    cout << students[n - k] << '\n';
    delete[] students;
}