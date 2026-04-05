#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string result;
    int temp = n / 4;
    if (n % 4) {
        temp++;
    }
    while (temp) {
        result += "long ";
        temp--;
    }
    result += "int";
    cout << result << '\n';
}
