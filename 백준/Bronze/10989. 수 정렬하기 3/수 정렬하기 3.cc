#include <cstdio>
#define MAX 10001

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int count[MAX] = {0, };
    int max = 1;
    int input;
    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        count[input]++;
        if (input > max)
            max = input;
    }

    for (int i = 1; i <= max; i++) {
        while(count[i]) {
            printf("%d\n", i);
            count[i]--;
        }
    }
}