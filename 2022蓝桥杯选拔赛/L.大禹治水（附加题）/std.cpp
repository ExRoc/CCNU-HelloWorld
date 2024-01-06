#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int matrixSize = 50;
const int maxn = 100000 + 100;
int MOD;
bool isDoorway[50];

LL add(LL a, LL b) {
    a += b;
    if(a >= MOD) {
        return a - MOD;
    }
    return a;
}

struct Matrix {
    int size;
    LL num[matrixSize][matrixSize];

    const Matrix& operator=(const Matrix &m) {
        size = m.size;
        for(int i = 0; i < size; ++i) {
            memcpy(num[i], m.num[i], sizeof(LL) * size);
        }
        return (*this);
    }

    void init() {
        for(int i = 0; i < size; ++i) {
            memset(num[i], 0, sizeof(LL) * size);
            num[i][i] = 1;
        }
    }

    void clear() {
        for (int i = 0; i < size; ++i) {
            memset(num[i], 0, sizeof(LL) * size);
        }
    }

    void set(int n, int m) {
        size = n;
        int u, v;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            --u;
            --v;
            ++num[u][v];
            if (u != v) {
                ++num[v][u];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (j == 0) {
                    num[i][j] = 0;
                } else {
                    if (i == 0) {
                        isDoorway[j] = (num[i][j] != 0);
                    }
                    num[i][j] %= MOD;
                }
            }
        }
    }

    const Matrix& operator*(const Matrix &m) const {
        static Matrix ans;
        ans.size = m.size;
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                ans.num[i][j] = 0;
                for(int k = 0; k < size; ++k) {
                    ans.num[i][j] = add(ans.num[i][j], num[i][k] * m.num[k][j] % MOD);
                }
            }
        }
        return ans;
    }

    const Matrix& operator*=(const Matrix &m) {
        (*this) = (*this) * m;
        return *this;
    }

    const Matrix& operator+(const Matrix &m) const {
        static Matrix ans;
        ans.size = m.size;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                ans.num[i][j] = add(num[i][j], m.num[i][j]);
            }
        }
        return ans;
    }

    const Matrix& operator+=(const Matrix &m) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                num[i][j] = add(num[i][j], m.num[i][j]);
            }
        }
        return *this;
    }

    LL hash() {
        LL ret = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 1; j < size; ++j) {
                ret = ret * 10 + num[i][j];
            }
        }
        return ret;
    }
};

Matrix one, zero;

struct MMatrix {
    int size;
    Matrix m[2][2];

    void set(const Matrix &m) {
        size = 2;
        this->m[0][0] = m;
        this->m[0][1] = one;
        this->m[1][0] = zero;
        this->m[1][1] = one;
    }

    const MMatrix& operator=(const MMatrix &mm) {
        size = mm.size;
        for(int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                m[i][j] = mm.m[i][j];
            }
        }
        return (*this);
    }

    void init() {
        for(int i = 0; i < size; ++i) {
            m[i][i] = one;
            m[i][i ^ 1] = zero;
        }
    }

    const MMatrix& operator*=(const MMatrix &mm) {
        static MMatrix ans;
        ans.size = size;
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                ans.m[i][j] = zero;
                for(int k = 0; k < size; ++k) {
                    ans.m[i][j] += m[i][k] * mm.m[k][j];
                }
            }
        }
        (*this) = ans;
        return ans;
    }

    void fastPow(LL n) {
        static MMatrix ans;
        ans.size = size;
        for(ans.init(); n != 0; n >>= 1) {
            if((n & 1) == 1) {
                ans *= (*this);
            }
            (*this) *= (*this);
        }
        (*this) = ans;
    }
};

int T, n, m, k, ans;
Matrix matrix, matrixSum;
MMatrix mmatrix;

char kStr[maxn];
LL h;
LL pow10[20];
map<LL, int> hashIndex;
vector<LL> hs;

int getNum(LL h, int x, int y) {
    int r = n - 1 - x;
    int c = n - 1 - y;
    return h / pow10[r * (n - 1) + c] % 10;
}

void solve1() {
    scanf("%d%d%d%d", &n, &m, &k, &MOD);
    matrix.set(n, m);
    one.size = n;
    one.init();
    zero.size = n;
    zero.clear();
    mmatrix.set(matrix);
    mmatrix.fastPow(k);
    mmatrix.m[0][1] *= matrix;
    ans = 0;
    for (int i = 1; i < n; ++i) {
        if (isDoorway[i]) {
            ans = (ans + mmatrix.m[0][1].num[0][i]) % MOD;
        }
    }
    printf("%d\n", ans);
}

void solve2() {
    pow10[0] = 1;
    for (int i = 1; i < 18; ++i) {
        pow10[i] = pow10[i - 1] * 10;
    }

    scanf("%d%d%s%d", &n, &m, kStr, &MOD);
    matrix.set(n, m);
    matrixSum.size = n;
    matrixSum.clear();
    h = matrixSum.hash();
    do {
        hashIndex[h] = hs.size();
        hs.push_back(h);
        matrixSum = matrixSum * matrix + matrix;
        h = matrixSum.hash();
    } while (hashIndex.find(h) == hashIndex.end());

    int loopIndex = hashIndex[h];
    int loopLength = hs.size() - loopIndex;
    int index = 0;
    for (int i = 0; kStr[i] != '\0'; ++i) {
        index = (index * 10 + (kStr[i] - '0')) % loopLength;
    }
    index = ((index - loopIndex) % loopLength + loopLength) % loopLength + loopIndex;
    for (int j = 1; j < n; ++j) {
        if (isDoorway[j]) {
            ans = (ans + getNum(hs[index], 0, j)) % MOD;
        }
    }
    printf("%d\n", ans);
}

int main() {
    scanf("%d", &T);
    if (T <= 30) {
        solve1();
        return 0;
    }
    solve2();

    return 0;
}
