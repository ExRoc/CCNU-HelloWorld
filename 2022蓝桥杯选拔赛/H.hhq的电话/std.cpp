#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
LL n;
double nn;
LL ansAnd, ansOr, ansXor;
LL sumAnd, sumOr, sumXor;
LL num[maxn];
LL dig[32][maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    nn = n * n;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        for (int j = 0; j < 31; ++j) {
            dig[j][i] = (num[i] >> j) & 1;
        }
    }
    for (int i = 0; i < 31; ++i) {
        LL lastIndexOfZero = 0;
        LL lastIndexOfOne = 0;
        LL cnt0 = 0;
        LL cnt1 = 0;
        sumAnd = sumOr = sumXor = 0;
        for (int j = 1; j <= n; ++j) {
            if (dig[i][j] == 0) {
                sumOr += lastIndexOfOne * 2;
                lastIndexOfZero = j;
                sumXor += cnt1 * 2;
                ++cnt0;
            } else {
                sumAnd += (j - lastIndexOfZero - 1) * 2;
                ++sumAnd;
                sumOr += j * 2 - 1;
                lastIndexOfOne = j;
                sumXor += cnt0 * 2 + 1;
                swap(cnt0, cnt1);
                ++cnt1;
            }
        }
        ansAnd += sumAnd << i;
        ansOr += sumOr << i;
        ansXor += sumXor << i;
    }
    printf("%.3f %.3f %.3f\n", ansXor / nn, ansAnd / nn, ansOr / nn);

    return 0;
}
