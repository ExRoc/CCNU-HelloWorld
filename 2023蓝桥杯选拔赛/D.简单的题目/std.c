#include <stdio.h>
int T, a;
long long n;
int num[3] = {1, 4, 2};

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%lld", &a, &n);
        if (a == 0) {
            printf("0\n");
            continue;
        }
        long long cnt = -1;
        for (int i = 1; i <= n; ++i) {
            if (a % 2 == 0) {
                a /= 2;
            } else {
                a = a * 3 + 1;
            }
            if (a == 1) {
                cnt = i;
                break;
            }
        }
        if (cnt == -1) {
            printf("%d\n", a);
            continue;
        }
        printf("%d\n", num[(n - cnt) % 3]);
    }

    return 0;
}
