#include <iostream>
#include <string>

using namespace std;

int main() {
    string input[5];
    for (auto& i : input) {
        cin >> i;
    }
    for (int j = 0; j < 15; j++) {
        for (auto& i : input) {
            if (i.size() > j) {
                cout << i.at(j);
            }
        }
    }
}
