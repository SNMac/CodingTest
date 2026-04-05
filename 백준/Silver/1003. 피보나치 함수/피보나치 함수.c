#include <stdio.h>

int zero, one;

int fibonacci(int n, int ary[]);

int main(void) {
    int testcase, input;
    int memo[41] = {0, };
    scanf("%d", &testcase);
    for (int i = 0; i < testcase; i++) {
        zero = 0;
        one = 0;
        scanf("%d", &input);
        if (input == 0) {
            printf("%d %d\n", 1, 0);
        } else if (input == 1) {
            printf("%d %d\n", 0, 1);
        }
        else {
            memo[0] = 0;
            memo[1] = 1;
            memo[2] = 1;
            fibonacci(input, memo);
            printf("%d %d\n", memo[input - 1], memo[input]);
        }

    }
    return 0;
}

int fibonacci(int n, int ary[]) {
    if (ary[n] == 0) {
        ary[n] = fibonacci(n - 1, ary) + fibonacci(n - 2, ary);
    }
    return ary[n];
}