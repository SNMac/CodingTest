#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<string> s;
    s.insert("ChongChong");

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string A, B;
        cin >> A >> B;
        auto itA = s.find(A);
        auto itB = s.find(B);
        if (itA != s.end()) {
            s.insert(B);
        } else if (itB != s.end()) {
            s.insert(A);
        }
    }
    cout << s.size() << '\n';
}
