#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    int r = a % b;
    if (r == 0) {
        return b;
    }
    return gcd(b, r);
}

int main() {
    int n;
    cin >> n;
    vector<int> diff;
    int temp = 0;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (temp != 0) {
            temp = input - temp;
            diff.push_back(temp);
        }
        temp = input;
    }

    int gcd_result = diff.at(0);
    for (int i = 1; i < diff.size(); i++) {
        gcd_result = gcd(gcd_result, diff.at(i));
    }
    int result = 0;
    for (int i : diff) {
        result += i / gcd_result - 1;
    }
    cout << result << '\n';
}
