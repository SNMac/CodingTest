#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int num = 666;
    int count = 0;

    while(1) {
        int temp = num;
        while (temp) {
            v.push_back(temp % 10);
            temp /= 10;
        }

        bool successive = false;
        int sixCount = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 6) {
                if (successive) {
                    sixCount++;
                } else {
                    successive = true;
                    sixCount++;
                }
            } else {
                if (successive) {
                    successive = false;
                    sixCount = 0;
                }
            }
            if (sixCount == 3)
                break;
        }

        if (sixCount == 3)
            count++;

        if (n == count)
            break;
        v.clear();
        num++;
    }
    cout << num << '\n';
}