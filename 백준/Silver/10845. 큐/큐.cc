#include <iostream>

using namespace std;

class Queue {
    int f = 0, b = 0;
    int* qArr;
public:
    Queue(int n) {qArr = new int[n];}
    ~Queue() {delete[] qArr;}
    void push(int x) {qArr[b++] = x;}
    int pop() {return (f == b ? -1 : qArr[f++]);}
    int size() {return b - f;}
    int empty() {return (b - f == 0 ? 1 : 0);}
    int front() {return (f == b ? -1 : qArr[f]);}
    int back() {return (f == b ? -1 : qArr[b - 1]);}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Queue queue(n);
    for (int i = 0; i < n; i++) {
        string inst;
        cin >> inst;
        if (inst == "push") {
            int input;
            cin >> input;
            queue.push(input);
        } else if (inst == "pop") {
            cout << queue.pop() << '\n';
        } else if (inst == "size") {
            cout << queue.size() << '\n';
        } else if (inst == "empty") {
            cout << queue.empty() << '\n';
        } else if (inst == "front") {
            cout << queue.front() << '\n';
        } else
            cout << queue.back() << '\n';
    }
}