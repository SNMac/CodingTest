#include <iostream>
#include <string>

#define MAX 2000000
using namespace std;

class queue {
    int* arr;
    int f, b;
public:
    queue();
    ~queue() {delete arr;}
    void push(int k) {arr[++b] = k;}
    int pop() {return empty() ? -1 : arr[f++];}
    int size() {return b - f + 1;}
    int empty() {return b - f == -1 ? 1 : 0;}
    int front() {return empty() ? -1 : arr[f];}
    int back() {return empty() ? -1 : arr[b];}
};

queue::queue() {
    arr = new int[MAX];
    f = 0;
    b = -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    queue q;
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        if (input == "push") {
            int k;
            cin >> k;
            cin.ignore();
            q.push(k);
        } else if (input == "pop") {
            cout << q.pop() << '\n';
        } else if (input == "size") {
            cout << q.size() << '\n';
        } else if (input == "empty") {
            cout << q.empty() << '\n';
        } else if (input == "front") {
            cout << q.front() << '\n';
        } else if (input == "back") {
            cout << q.back() << '\n';
        }
    }
}
