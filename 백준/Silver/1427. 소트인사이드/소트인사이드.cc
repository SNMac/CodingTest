#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    while(n) {
        v.push_back(n % 10);
        n /= 10;
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++)
        cout << v[i];
    cout << '\n';
}