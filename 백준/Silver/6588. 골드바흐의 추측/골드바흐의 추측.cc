#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define MAX_SIZE 1000001

using namespace std;

int input;
bool notPrimeNum[MAX_SIZE];

int main() {
    FAST_IO

    for (int i = 3; i < MAX_SIZE; i += 2) {
        if (!notPrimeNum[i]) {
            for (int j = 3; i * j < MAX_SIZE; j += 2)
                notPrimeNum[i * j] = true;
        }
    }

    while (true) {
        int a = 0, b = 0;
        cin >> input;
        if (input == 0)
            break;

        for (int i = 3; i < MAX_SIZE; i += 2) {
            if (!notPrimeNum[i] && !notPrimeNum[input - i]) {
                a = i; b = input - i;
                break;
            }
        }
        if (a) {
            cout << input << " = " << a << " + " << b << '\n';
        } else {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }
}
