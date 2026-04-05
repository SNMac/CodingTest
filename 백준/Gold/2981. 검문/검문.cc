#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    return a % b ? gcd(b, a % b) : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    int gcdResult = arr[1] - arr[0];
    for (int i = 2; i < n; i++)
        gcdResult = gcd(gcdResult, arr[i] - arr[i - 1]);

    vector<int> ans;
    for (int i = 2; i * i <= gcdResult; i++) {
        if (gcdResult % i == 0) {
            ans.push_back(i);
            ans.push_back(gcdResult / i);
        }
    }
    ans.push_back(gcdResult);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (auto it : ans)
        cout << it << ' ';
    cout << '\n';
    delete[] arr;
}