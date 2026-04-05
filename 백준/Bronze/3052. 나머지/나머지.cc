#include <iostream>

using namespace std;

int main() {
   int* arr = new int[10];
   for (int i = 0; i < 10; i++)
       cin >> arr[i];

    for (int i = 0; i < 10; i++)
        arr[i] %= 42;

    bool diff;
    int res = 0;
    for (int i = 0; i < 10; i++) {
        diff = true;
        for (int j = i + 1; j < 10; j++) {
            if (arr[j] == arr[i])
                diff = false;
        }
        if (diff)
            res++;
    }

    cout << res << endl;
    delete[] arr;
}