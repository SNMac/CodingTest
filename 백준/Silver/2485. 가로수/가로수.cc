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
    vector<int> loc(n);
    vector<int> diff;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        loc[i] = input;
    }
    for (int i = 0; i < n - 1; i++) {
        diff.push_back(loc[i + 1] - loc[i]);
    }

    int gcd_result = gcd(diff[0], diff[1]);
    for (int i = 2; i < diff.size(); i++) {
        gcd_result = gcd(gcd_result, diff[i]);
    }
    int result = 0;
    for (int i = 0; i < diff.size(); i++) {
        result += diff[i] / gcd_result - 1;
    }
    cout << result << '\n';
}
