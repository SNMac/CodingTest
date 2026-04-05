#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == -1) {
            break;
        }

        vector<int> v;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                v.push_back(i);
            }
        }
        int total = 0;
        for (auto it : v) {
            total += it;
        }
        if (total == n) {
            cout << n << " =";
            for (int i = 0; i < v.size(); i++) {
                cout << ' ' << v.at(i);
                if (i != v.size() - 1) {
                    cout << " +";
                }
            }
            cout << '\n';
        } else {
            cout << n << " is NOT perfect." << '\n';
        }
    }
}
