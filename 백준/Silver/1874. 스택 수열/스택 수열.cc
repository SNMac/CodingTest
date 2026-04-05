#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<int> s;
    int n;
    cin >> n;
    int* arr = new int[n];
    char* output = new char[2 * n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int i = 1;
    int arrIndex = 0, outputIndex = 0;
    bool max = false;
    while(arrIndex < n) {
        if (!s.empty()) {
            if (s.top() == n)
                max = true;

            if (s.top() == arr[arrIndex]) {
                s.pop();
                output[outputIndex++] = '-';
                arrIndex++;
                continue;
            } else {
                if (max) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
        s.push(i++);
        output[outputIndex++] = '+';
    }
    delete[] arr;

    for (int o = 0; o < outputIndex; o++)
        cout << output[o] << '\n';
    delete[] output;
}