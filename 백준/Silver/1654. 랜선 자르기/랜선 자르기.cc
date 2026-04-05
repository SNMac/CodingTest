#include <iostream>
#include <vector>

using namespace std;

int k, n;

long long binSearch(const vector<long long>& v, long long max) {
    long long count;
    long long low = 1, high = max;
    long long mid, ret;
    while (low <= high) {
        mid = (high + low) / 2;
        count = 0;
        for (auto it : v)
            count += it / mid;
        if (count < n) {
            high = mid - 1;
            ret = high;
        } else {  // count >= n
            low = mid + 1;
            ret = mid;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k >> n;
    vector<long long> v;
    long long max = 0;
    for (int i = 0; i < k; i++) {
        long long len;
        cin >> len;
        if (max < len)
            max = len;
        v.push_back(len);
    }
    cout << binSearch(v, max) << '\n';
}