#include <stdio.h>

typedef long long LL;
const LL MOD = 1000000007;
const int maxP = 17;
int n, m;
LL ans;
int bit[61];
LL dp[1001][1 << 17];
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

    // 找出需要遍历多少个质数，确定集合大小
    int cnt = 0;
    for (int i = 0; i < maxP; ++i) {
        if (prime[i] <= m) {
            ++cnt;
        }
    }

    // dp 转移
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (1 << cnt); ++j) {
            for (int k = 1; k <= m; ++k) {
                if ((j & bit[k]) == bit[k]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j ^ bit[k]]) % MOD;
                }
            }
        }
    }
    for (int i = 0; i < (1 << cnt); ++i) {
        ans = (ans + dp[n][i]) % MOD;
    }
    printf("%lld\n", ans);

    return 0;
}