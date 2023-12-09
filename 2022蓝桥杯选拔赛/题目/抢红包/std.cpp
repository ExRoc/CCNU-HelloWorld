#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 5000 + 100;
const LL MOD = 1000000007;
int n, m;
LL ans;
LL inv[maxn];
LL dp[2][maxn], sum[2][maxn];

void initInv() {
    inv[1] = 1;
    for(int i = 2; i < maxn; ++i) {
        inv[i] = (LL)(MOD - MOD / i) * inv[MOD % i] % MOD;
    }
}

int main() {
    initInv();

    scanf("%d%d", &n, &m);

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int nowIndex = i & 1;
        int preIndex = nowIndex ^ 1;

        sum[preIndex][0] = dp[preIndex][0] * inv[m - (n - i)] % MOD;
        for (int j = 1; j < m - (n - i); ++j) {
            sum[preIndex][j] = (sum[preIndex][j - 1] + dp[preIndex][j] * inv[m - (n - i) - j] % MOD) % MOD;
        }

        for (int j = i; j <= m - (n - i); ++j) {
            if (i - 1 == 0) {
                dp[nowIndex][j] = sum[preIndex][j - 1];
            } else {
                dp[nowIndex][j] = ((sum[preIndex][j - 1] - sum[preIndex][i - 2]) % MOD + MOD) % MOD;
            }
        }
    }

    for (int j = n - 1; j <= m - 1; ++j) {
        int preIndex = (n - 1) & 1;
        ans = (ans + dp[preIndex][j] * (m - j) % MOD) % MOD;
    }

    printf("%lld\n", ans);

    return 0;
}
