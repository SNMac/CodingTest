#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int sizeA, sizeB;
    cin >> sizeA >> sizeB;
    set<int> a;
    set<int> b;
    for (int i = 0; i < sizeA; i++) {
        int input;
        cin >> input;
        a.insert(input);
    }
    for (int i = 0; i < sizeB; i++) {
        int input;
        cin >> input;
        b.insert(input);
    }

    for (auto iter : b) {
        if (a.find(iter) == a.end())
            a.insert(iter);
        else
            a.erase(iter);
    }
    cout << a.size() << '\n';
}