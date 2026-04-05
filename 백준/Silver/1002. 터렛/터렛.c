#include <stdio.h>

int main(void) {
    int testnum;
    int distsqr;
    int result;
    int x1, y1, r1, x2, y2, r2;
    scanf("%d", &testnum);
    for (int i = 0; i < testnum; i++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        if (x1 == x2 && y1 == y2) {  // 두 원의 중심이 같음
            if (r1 == r2) {  // 반지름이 같은 원
                result = -1;
            }
            else if (r1 != r2) {  // 반지름이 다른 원
                result = 0;
            }
        }

        else {  // 두 원의 중심이 다름
            distsqr = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
            if (distsqr < r1 * r1 && distsqr >= r2 * r2) {  // 한 원 중심이 다른 원 내부에 존재
                if ((r1 - r2) * (r1 - r2) == distsqr) {  // 한 원이 다른 원 안에서 한 점에 내접
                    result = 1;
                }
                else if ((r1 - r2) * (r1 - r2) > distsqr) {  // 두 원이 만나지 않음
                    result = 0;
                }
                else if ((r1 - r2) * (r1 - r2) < distsqr) {
                    result = 2;
                }
            }
            else if (distsqr < r2 * r2 && distsqr >= r1 * r1) {  // 한 원 중심이 다른 원 내부에 존재
                if ((r2 - r1) * (r2 - r1) == distsqr) {
                    result = 1;
                }
                else if ((r2 - r1) * (r2 - r1) > distsqr) {
                    result = 0;
                }
                else if ((r2 - r1) * (r2 - r1) < distsqr) {
                    result = 2;
                }
            }
            else if (distsqr < r1 * r1 && distsqr < r2 * r2) {
                if ((r2 - r1) * (r2 - r1) == distsqr || (r1 - r2) * (r1 - r2) == distsqr) {
                    result = 1;
                }
                else if ((r2 - r1) * (r2 - r1) > distsqr || (r1 - r2) * (r1 - r2) > distsqr) {
                    result = 0;
                }
                else if ((r2 - r1) * (r2 - r1) < distsqr || (r1 - r2) * (r1 - r2) < distsqr){
                    result = 2;
                }
            }
            else {  // 한 원 중심이 서로의 외부에 존재
                if (distsqr == (r1 + r2) * (r1 + r2)) {  // 한 점에서 만남
                    result = 1;
                }
                else if (distsqr > (r1 + r2) * (r1 + r2)) {  // 만나지 않음
                    result = 0;
                }
                else if (distsqr < (r1 + r2) * (r1 + r2)) {  // 두 점에서 만남
                    result = 2;
                }
            }
        }
        printf("%d\n", result);
    }
    return 0;
}