#include <iostream>
#include <string>
#include <map>
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

    map<string, int> m_freq;
    vector<pair<string, int>> v;

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        if (word.size() >= M) {
            auto it = m_freq.find(word);
            if (it != m_freq.end()) {
                it->second++;
            } else {
                m_freq.insert({word, 1});
            }
        }
    }

    v.reserve(m_freq.size());
    for (const auto& it : m_freq)
        v.emplace_back(it.first, it.second);
    sort(v.begin(), v.end(), cmp);
    for (const auto& it : v)
        cout << it.first << '\n';
}
