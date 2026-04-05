#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    return a % b ? GCD(b, a % b) : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<pair<int, int>> ans;
    for (int i = 1; i < n; i++) {
        int gcd  = GCD(arr[0] * 2, arr[i] * 2);
        int top = arr[0] * 2 / gcd;
        int bottom = arr[i] * 2 / gcd;
        ans.emplace_back(top, bottom);
    }

    for (auto it : ans)
        cout << it.first << '/' << it.second << '\n';
    delete[] arr;
}