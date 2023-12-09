#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1000000 + 100;
const int maxnm = 100000 + 100;
int T, n, m;
bool ans;
int nums[maxnm], degIn[maxnm], numsTmp[maxnm];
int idxOfNum[maxn];
int vis[maxn];
vector<int> G[maxnm];
queue<int> que;

inline int id(int x, int y) {
    return x * m + y;
}

bool topsort(int n) {
    while (!que.empty()) {
        que.pop();
    }

    for (int i = 0; i < n; ++i) {
        if (degIn[i] == 0) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        int tmp = que.front();
        que.pop();
        for (auto pos: G[tmp]) {
            --degIn[pos];
            if (degIn[pos] == 0) {
                que.push(pos);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (degIn[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        memset(vis, -1, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &nums[id(i, j)]);
           }
        }

        for (int i = 0; i < m; ++i) {
            G[i].clear();
            degIn[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x = nums[id(i, j)];
                if (x == 0) {
                    continue;
                }
                vis[x] = i;
                idxOfNum[x] = j;
            }
            for (int j = 0; j < m; ++j) {
                int x = nums[id(i, j)];
                if (x == 0) {
                    continue;
                }
                for (int k = x + x; k < maxn; k += x) {
                    if (vis[k] == i) {
                        G[idxOfNum[k]].push_back(j);
                        ++degIn[j];
                    }
                }
            }
        }
        if (!topsort(m)) {
            printf("no\n");
            continue;
        }

        for (int i = 0; i < n; ++i) {
            G[i].clear();
            degIn[i] = 0;
        }
        for (int j = 0; j < m; ++j) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                int x = nums[id(i, j)];
                if (x == 0) {
                    continue;
                }

                numsTmp[cnt++] = x;
                idxOfNum[x] = i;
            }
            sort(numsTmp, numsTmp + cnt);
            for (int i = 1; i < cnt; ++i) {
                G[idxOfNum[numsTmp[i]]].push_back(idxOfNum[numsTmp[i - 1]]);
                ++degIn[idxOfNum[numsTmp[i - 1]]];
            }
        }
        if (!topsort(n)) {
            printf("no\n");
            continue;
        }
        printf("yes\n");
    }

    return 0;
}