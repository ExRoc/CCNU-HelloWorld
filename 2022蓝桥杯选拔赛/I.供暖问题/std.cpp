#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
struct Node {
    int u, v;
    LL c;

    Node() {}
    Node(int uu, int vv, LL cc) {
        u = uu;
        v = vv;
        c = cc;
    }
};

bool operator<(const Node &a, const Node &b) {
    return a.c < b.c;
}

int n, m, u, v, c, cnt;
LL ans;
int fa[maxn];
Node node[maxn];

void init() {
    for (int i = 0; i <= n; ++i) {
        fa[i] = i;
    }
}

int Find(int x) {
    return x == fa[x]? x: fa[x] = Find(fa[x]);
}

void unit(int x, int y) {
    fa[Find(x)] = Find(y);
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    init();
    for (int i = 1; i <= n; ++i) {
        cin >> c;
        node[cnt++] = Node(0, i, c);
    }
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> c;
        node[cnt++] = Node(u, v, c);
    }
    sort(node, node + cnt);
    for (int i = 0; i < cnt; ++i) {
        if (Find(node[i].u) != Find(node[i].v)) {
            ans += node[i].c;
            unit(node[i].u, node[i].v);
        }
    }
    cout << ans << endl;

    return 0;
}
