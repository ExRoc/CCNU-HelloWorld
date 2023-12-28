#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    n %= 10000;
    if (n >= 2020) {
        printf("1024\n");
    } else {
        printf("HelloWorld\n");
    }

    return 0;
}
