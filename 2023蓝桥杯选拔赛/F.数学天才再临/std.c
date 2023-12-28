#include <stdio.h>

typedef long long LL;
const LL MOD = 1000000007;
const int maxP = 17;
int n, m;
LL ans;
int bit[61];
LL C[1001][1001];
LL dp[61][1 << 17];
int prime[17] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53 , 59};

int main() {
    scanf("%d%d", &n, &m);

    // bit 预处理
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < maxP; ++j) {
            if (i % prime[j] == 0) {
                bit[i] |= (1 << j);
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = (C[i - 1][j - 1] + C[i -  1][j]) % MOD;
            }
        }
    }

    // 找出需要遍历多少个质数，确定集合大小
    int cnt = 0;
    for (int i = 0; i < maxP; ++i) {
        if (prime[i] <= m) {
            ++cnt;
        }
    }

    // dp 转移
    dp[0][0] = 1;
    int mn = cnt < n ? cnt : n;
    for (int i = 0; i <= mn; ++i) {
        LL tmp = 0;
        for (int j = 0; j < (1 << cnt); ++j) {
            if (dp[i][j] == 0) {    // 减少状态转移次数的小优化
                continue;
            }
            for (int k = 2; k <= m; ++k) {
                if ((j & bit[k]) == 0) {
                    dp[i + 1][j | bit[k]] = (dp[i + 1][j | bit[k]] + dp[i][j]) % MOD;
                }
            }
            tmp = (tmp + dp[i][j]) % MOD;
        }
        ans = (ans + tmp * C[n][i] % MOD) % MOD;
    }
    printf("%lld\n", ans);

    return 0;
}