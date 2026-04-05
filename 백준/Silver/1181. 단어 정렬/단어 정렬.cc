#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
    if (a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        if (find(v.begin(), v.end(), input) == v.end())
            v.push_back(input);
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
}