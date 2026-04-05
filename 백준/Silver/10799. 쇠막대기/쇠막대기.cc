#include <iostream>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int main() {
    FAST_IO

    string input;
    input.reserve(100000);
    cin >> input;
    int total = 0;
    int cut = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            if (input[i + 1] == ')') {  // 레이저
                total += cut;
                i++;
            } else {  // input[i + 1] == '(', 쇠막대기 시작
                cut++;
            }
        } else {  // input[i] == ')', 쇠막대기 끝
            cut--;
            total++;
        }
    }
    cout << total << '\n';
}
