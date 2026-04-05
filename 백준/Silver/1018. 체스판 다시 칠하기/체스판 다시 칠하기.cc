#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string* board = new string[n];
    for (int i = 0; i < n; i++)
        cin >> board[i];

    bool cont = true;
    int startY = 0, startX = 0;
    int min = -1;
    while (cont) {
        int countB = 0, countW = 0;
        for (int y = startY; y < startY + 8; y++) {
            for (int x = startX; x < startX + 8; x++) {
                if ((y - startY) % 2 == 0) {
                    if ((x - startX) % 2 == 0) {
                        if (board[y][x] == 'B')
                            countW++;
                        else
                            countB++;
                    } else {
                        if (board[y][x] == 'B')
                            countB++;
                        else
                            countW++;
                    }
                } else {
                    if ((x - startX) % 2 == 0) {
                        if (board[y][x] == 'B')
                            countB++;
                        else
                            countW++;
                    } else {
                        if (board[y][x] == 'B')
                            countW++;
                        else
                            countB++;
                    }
                }
            }
        }

        if (countB < countW) {
            if (min == -1 || min > countB)
                min = countB;
        } else {
            if (min == -1 || min > countW)
                min = countW;
        }

        if (min == 0)
            break;

        if (startX + 8 != m) {
            startX++;
        } else {
            startX = 0;
            if (startY + 8 != n)
                startY++;
            else
                cont = false;
        }
    }
    cout << min << '\n';
    delete[] board;
}