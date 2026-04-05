#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int arr[8];
    for (int& i : arr)
        cin >> i;

    string result = "mixed\n";
    if (arr[0] == 1) {
        int asc = 1;
        bool isAsc = true;
        for (int i = 1; i < 8; i++) {
            if (arr[i] != ++asc)
                isAsc = false;
        }
        if (isAsc)
            result = "ascending\n";
    } else if (arr[0] == 8) {
        int dsc = 8;
        bool isDsc = true;
        for (int i = 1; i < 8; i++) {
            if (arr[i] != --dsc)
                isDsc = false;
        }
        if (isDsc)
            result = "descending\n";
    }
    cout << result;
}