#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string input;
    cin >> input;
    int total = 0;
    for (int i = 0; i < n; i++)
        total += input[i] - '0';
    cout << total << endl;
}