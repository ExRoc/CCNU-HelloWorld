#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long long sum = 0, ans = 0, x = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &x);
        ans += x * sum;
        sum += x;
    }
    printf("%ld\n", ans);
    return 0;
}
