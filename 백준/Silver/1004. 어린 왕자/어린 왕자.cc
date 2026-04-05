#include <iostream>
#include <vector>
#include <tuple>

#define POW(n) (n) * (n)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int n;
        cin >> n;
        vector<tuple<int, int, int>> planet;
        for (int j = 0; j < n; j++) {
            int cx, cy, r;
            cin >> cx >> cy >> r;
            planet.emplace_back(cx, cy, r);
        }
        int count = 0;
        for (auto it : planet) {
            int distPrincePow = POW(x1 - get<0>(it)) + POW(y1 - get<1>(it));
            int distDestPow = POW(x2 - get<0>(it)) + POW(y2 - get<1>(it));
            if (distPrincePow < POW(get<2>(it))) {
                if (distDestPow > POW(get<2>(it)))
                    count++;
            } else {  // distPrincePow > POW(get<2>(it))
                if (distDestPow < POW(get<2>(it)))
                    count++;
            }
        }
        cout << count << '\n';
    }
}