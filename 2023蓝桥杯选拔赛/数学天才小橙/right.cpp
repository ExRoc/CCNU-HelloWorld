#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1000 + 100;
const LL MOD = 1000000007;
int n, m;
int num[maxn];
LL fenzi, fenmu;

LL fastPow(LL res, LL n) {
    LL ans;
    for (ans = 1; n != 0; n >>= 1) {
        if (n & 1) {
            ans = ans * res % MOD;
        }
        res = res * res % MOD;
    }
    return ans;
}

LL inv(LL x) {
    return fastPow(x, MOD - 2);
}

void dfs(int depth) {
    if (depth == n) {
        ++fenzi;
        return ;
    }
    for (int i = 1; i <= m; ++i) {
        bool flag = true;
        for (int j = 0; j < depth; ++j) {
            if (__gcd(num[j], i) != 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            num[depth] = i;
            dfs(depth + 1);
        }
    }
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif // ExRoc
    ios::sync_with_stdio(false);

    cin >> n >> m;
    dfs(0);
    fenmu = fastPow(inv(m), n);
    cout << fenzi * fenmu % MOD << endl;

    return 0;
}
