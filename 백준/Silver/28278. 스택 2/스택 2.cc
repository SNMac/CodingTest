#include <iostream>

using namespace std;

class Stack {
    int top;
    int* arr;
public:
    Stack() {top = -1; arr = new int[1000000]{};}
    ~Stack() {delete arr;}
    void push(int x) {arr[++top] = x;}
    int pop() {return top == -1 ? -1 : arr[top--];}
    int getSize() {return top + 1;}
    int isEmpty() {return top == -1 ? 1 : 0;}
    int getTop() {return top == -1 ? -1 : arr[top];}
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Stack s;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int cmd;
        cin >> cmd;
        switch (cmd) {
            case 1 :
                int x;
                cin >> x;
                s.push(x);
                break;

            case 2 :
                cout << s.pop() << '\n';
                break;

            case 3 :
                cout << s.getSize() << '\n';
                break;

            case 4 :
                cout << s.isEmpty() << '\n';
                break;

            case 5 :
                cout << s.getTop() << '\n';
                break;
        }
    }
}