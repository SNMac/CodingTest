#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second == b.second) {
        if (a.first.length() == b.first.length()) {
            return a.first < b.first;
        }
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, int> hashm_freq;
    vector<pair<string, int>> v;

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        if (word.size() >= M) {
            hashm_freq[word]++;
        }
    }

    v.reserve(hashm_freq.size());
    for (const auto& it : hashm_freq)
        v.emplace_back(it.first, it.second);
    sort(v.begin(), v.end(), cmp);
    for (const auto& it : v)
        cout << it.first << '\n';
}
