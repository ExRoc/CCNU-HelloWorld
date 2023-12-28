#include<bits/stdc++.h>
using namespace std;

bool f[10007];
int main() {
    int n, sum = 0, x;
    cin >> n;
    f[0] = 1;//初始情况集合为空时有方案
    for (int i = 1;i <= n;++i) {
        cin >> x;
        for (int j = 10000; j >= x; --j) {
            f[j] |= f[j - x];
        }
        sum += x;
    }
    for (int i = sum / 2;i >= 0;--i) {
        if (f[i]) {
            cout << sum - i;
            break;
        }
    }
    return 0;
}