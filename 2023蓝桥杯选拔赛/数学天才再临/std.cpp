#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MOD = 1000000007;
int n, m;
int bit[51];
LL dp[1001][1 << 15];
int prime[9] = {2,3,5,7,11,13,17,19,23};
int bigPrime[6] = {29,31,37,41,43,47};
bool isBigPrime[51];
LL C[7][7];

LL A(int n, int m) {
    LL ret = 1;
    for (int i = 0; i < m; ++i) {
        ret = (ret * (n - i)) % MOD;
    }
    return ret;
}

int main() {
    for (int i = 0; i < 6; ++i) {
        isBigPrime[bigPrime[i]] = true;
    }
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == i || j == 0) {
                C[i][j] = 1;
            } else {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
    }

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (i % prime[j] == 0) {
                bit[i] |= (1 << j);
            }
        }
    }
    int idx = upper_bound(prime, prime + 9, m) - prime;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j < (1 << idx); ++j) {
            for (int k = 1; k <= m; ++k) {
                if (isBigPrime[k]) {
                    continue;
                }
                if ((j & bit[k]) == bit[k]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j ^ bit[k]]) % MOD;
                }
            }
        }
    }
    int up = upper_bound(bigPrime, bigPrime + 6, m) - bigPrime;

    LL ans = 0;
    for (int i = 0; i <= up && i <= n; ++i) {
        LL tmp = 0;
        for (int j = 0; j < (1 << idx); ++j) {
            tmp = (tmp + dp[n - i][j]) % MOD;
        }
        ans = (ans + tmp * C[up][i] % MOD * A(n, i) % MOD) % MOD;
    }
    cout << ans << endl;

    return 0;
}