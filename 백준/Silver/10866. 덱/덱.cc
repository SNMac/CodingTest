#include <iostream>

using namespace std;

class Deque {
    int f, b;
    int* deqArr;
public:
    Deque(int n) {deqArr = new int[n * 2]; f = n; b = n + 1;}
    ~Deque() {delete[] deqArr;}
    void push_front(int x) { deqArr[f--] = x;}
    void push_back(int x) { deqArr[b++] = x;}
    int pop_front() {return (b - f == 1 ? -1 : deqArr[++f]);}
    int pop_back() {return (b - f == 1 ? -1 : deqArr[--b]);}
    int size() {return b - f - 1;}
    int empty() {return (b - f == 1 ? 1 : 0);}
    int front() {return (b - f == 1 ? -1 : deqArr[f + 1]);}
    int back() {return (b - f == 1 ? -1 : deqArr[b - 1]);}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Deque deq(n);
    for (int i = 0; i < n; i++) {
        string inst;
        cin >> inst;
        if (inst == "push_front") {
            int input;
            cin >> input;
            deq.push_front(input);
        } else if (inst == "push_back") {
            int input;
            cin >> input;
            deq.push_back(input);
        } else if (inst == "pop_front") {
            cout << deq.pop_front() << '\n';
        } else if (inst == "pop_back") {
            cout << deq.pop_back() << '\n';
        } else if (inst == "size") {
            cout << deq.size() << '\n';
        } else if (inst == "empty") {
            cout << deq.empty() << '\n';
        } else if (inst == "front") {
            cout << deq.front() << '\n';
        } else
            cout << deq.back() << '\n';
    }
}