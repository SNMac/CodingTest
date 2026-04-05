#include <iostream>
#include <string>

using namespace std;

void recur(int f, int t, string& str) {
    int interval = (t - f) / 3;
    if (interval == 0)
        return;
    for (int i = f + interval; i < t - interval; i++)
        str[i] = ' ';
    recur(f, f + interval, str);
    recur(t - interval, t, str);
}

int main() {
    int N = 0;
    while (cin >> N) {
        int len = 1;
        for (int i = 0; i < N; i++)
            len *= 3;
        string str;
        for (int i = 0; i < len; i++)
            str += "-";
        recur(0, len, str);
        cout << str << '\n';
    }
}