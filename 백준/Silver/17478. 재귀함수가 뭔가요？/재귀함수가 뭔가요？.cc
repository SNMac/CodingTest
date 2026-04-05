#include <iostream>
#include <string>

using namespace std;

string print[7];

void append(int k, int index) {
    int rddcy = k * 4;
    for (int i = 0; i < rddcy; i++)
        cout << '_';
    cout << print[index];
}

void recur(int n, int k) {
    if (k == 0) {
        for (int i = 0; i <= 4; i++)
            append(k, i);
    } else if (k == n) {
        append(k, 1);
        append(k, 5);
        append(k, 6);
        return;
    } else {
        for (int i = 1; i <= 4; i++)
            append(k, i);
    }

    recur(n, k + 1);
    append(k, 6);
}

int main() {
    int n;
    cin >> n;
    print[0] = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    print[1] = "\"재귀함수가 뭔가요?\"\n";
    print[2] = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    print[3] = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    print[4] = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
    print[5] = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
    print[6] = "라고 답변하였지.\n";
    recur(n, 0);
}