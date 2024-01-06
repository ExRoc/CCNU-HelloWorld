#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007;
int n;
LL m;

inline LL div2(LL x) {
    if (x >= MOD) {
        x -= MOD;
    }
    if (x % 2 == 0) {
        return x / 2;
    }
    return (x + MOD) / 2;
}

int main() {
    scanf("%d%lld", &n, &m);
    for (int i = 1; i < n; ++i) {
        LL l = 1;
        LL r = m - (n - i);
        m = ((m - div2(l + r)) % MOD + MOD) % MOD;
    }
    printf("%lld\n", m);

    return 0;
}
