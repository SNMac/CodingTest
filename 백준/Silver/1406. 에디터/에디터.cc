#include <iostream>
#include <string>
#include <deque>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int main() {
    FAST_IO

    deque<char> l_deq;
    deque<char> r_deq;
    string str;
    cin >> str;
    for (auto c : str)
        l_deq.push_back(c);
    int M;
    cin >> M;
    cin.ignore();
    for (int i = 0; i < M; i++) {
        string cmd;
        getline(cin, cmd);
        switch (cmd.front()) {
            case 'L' :  // 커서 왼쪽으로
                if (!l_deq.empty()) {
                    r_deq.push_front(l_deq.back());
                    l_deq.pop_back();
                }
                break;

            case 'D' :  // 커서 오른쪽으로
                if (!r_deq.empty()) {
                    l_deq.push_back(r_deq.front());
                    r_deq.pop_front();
                }
                break;

            case 'B' :  // 커서 왼쪽 문자 삭제
                if (!l_deq.empty())
                    l_deq.pop_back();
                break;

            case 'P' :  // 문자 c를 커서 왼쪽에 추가
                char c = cmd.back();
                l_deq.push_back(c);
                break;
        }
    }
    for (auto it : l_deq)
        cout << it;
    for (auto it : r_deq)
        cout << it;
    cout << '\n';
}
