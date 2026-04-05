#include <iostream>

using namespace std;

class Stack {
    int stkSize = 0;
    int* stkArr;
public:
    Stack(int size) {stkArr = new int[size];}
    ~Stack() {delete[] stkArr;}
    void push(int n) {stkArr[stkSize++] = n;}
    int pop() {return (stkSize == 0 ? -1 : stkArr[--stkSize]);}
    int size() {return stkSize;}
    int empty() {return (stkSize == 0 ? 1 : 0);}
    int top() {return (stkSize == 0 ? -1 : stkArr[stkSize - 1]);}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Stack stack(n);
    for (int i = 0; i < n; i++) {
        string inst;
        cin >> inst;
        if (inst == "push") {
            int input;
            cin >> input;
            stack.push(input);
        } else if (inst == "pop") {
            cout << stack.pop() << '\n';
        } else if (inst == "size") {
            cout << stack.size() << '\n';
        } else if (inst == "empty") {
            cout << stack.empty() << '\n';
        } else {  // inst == "top"
            cout << stack.top() << '\n';
        }
    }
}