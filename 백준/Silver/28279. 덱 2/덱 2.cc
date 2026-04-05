#include <iostream>
#include <string>

#define MAX 2000001

using namespace std;

class Deck {
    int* arr;
    int f, b;
public:
    Deck();
    ~Deck() {delete arr;}
    void pushFront(int x) {arr[f--] = x;}  // 1
    void pushBack(int x) {arr[++b] = x;}  // 2
    int popFront() {return getSize() == 0 ? -1 : arr[++f];}  // 3
    int popBack() {return getSize() == 0 ? -1 : arr[b--];}  // 4
    int getSize() {return b - f;}  // 5
    int isEmpty() {return getSize() == 0 ? 1 : 0;}  // 6
    int getFront() {return getSize() == 0 ? -1 : arr[f + 1];}  // 7
    int getBack() {return getSize() == 0 ? -1 : arr[b];}  // 8
};

Deck::Deck() {
    arr = new int[MAX];
    f = MAX / 2;
    b = MAX / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Deck d;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int inst, x;
        cin >> inst;
        switch (inst) {
            case 1 :
                cin >> x;
                d.pushFront(x);
                break;

            case 2 :
                cin >> x;
                d.pushBack(x);
                break;

            case 3 :
                cout << d.popFront() << '\n';
                break;

            case 4 :
                cout << d.popBack() << '\n';
                break;

            case 5 :
                cout << d.getSize() << '\n';
                break;

            case 6 :
                cout << d.isEmpty() << '\n';
                break;

            case 7 :
                cout << d.getFront() << '\n';
                break;

            case 8 :
                cout << d.getBack() << '\n';
                break;
        }
    }
}
