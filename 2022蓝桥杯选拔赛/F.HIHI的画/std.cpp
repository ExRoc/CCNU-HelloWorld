#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1000 + 100;
int n, row, col;
char str[maxn][maxn];

void dfs(int r1, int c1, int r2, int c2) {
    if (r1 == r2 && c1 == c2) {
        str[r1][c1] = '*';
        return ;
    }
    int dr = r2 - r1;
    int dc = c2 - c1;
    dr /= 2;
    dc /= 3;
    dfs(r1, c1 + dc, r1 + dr, c1 + dc * 2);
    dfs(r1 + dr, c1, r1 + 2 * dr, c1 + dc);
    dfs(r1 + dr, c1 + dc, r1 + 2 * dr, c1 + 2 * dc);
    dfs(r1 + dr, c1 + 2 * dc, r1 + 2 * dr, c1 + 3 * dc);
}

int main() {
    cin >> n;
    row = 1;
    col = 1;
    for (int i = 0; i < n; ++i) {
        row *= 2;
        col *= 3;
    }
    memset(str, '.', sizeof(str));
    for (int i = 0; i < row; ++i) {
        str[i][col] = '\0';
    }
    dfs(0, 0, row, col);
    for (int i = 0; i < row; ++i) {
        printf("%s\n", str[i]);
    }

    return 0;
}
