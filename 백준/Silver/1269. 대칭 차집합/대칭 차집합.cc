#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int sizeA, sizeB;
    cin >> sizeA >> sizeB;
    set<int> a;
    for (int i = 0; i < sizeA; i++) {
        int input;
        cin >> input;
        a.insert(input);
    }
    for (int i = 0; i < sizeB; i++) {
        int input;
        cin >> input;
        if (a.find(input) == a.end())
            a.insert(input);
        else
            a.erase(input);

    }
    cout << a.size() << '\n';
}