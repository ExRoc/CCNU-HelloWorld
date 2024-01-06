#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int testCases = 50;
ofstream fout;
int T, n, m, k, p, u, v;

string numToStr(int x) {
    string str;
    while (x != 0) {
        str = char('0' + x % 10) + str;
        x /= 10;
    }
    return str;
}

string getFileName(int index) {
    return "data/" + numToStr(index) + ".in";
}

int getRand(int l, int r) {
    return (LL)rand() * rand() * rand() % (r - l + 1) + l;
}

void writeToFile() {
    for (int i = 0; i < m; ++i) {
        u = getRand(1, n);
        v = getRand(1, n);
        fout << u << " " << v << endl;
    }
}

int main() {
    srand(time(0));

    // data in 20%, 2 <= n,m,k <= 7, p = 1e9+7
    int one = testCases * 20 / 100;
    for (int i = 1; i <= one; ++i) {
        fout.open(getFileName(i));
        fout << i << endl;
        n = getRand(5, 7);
        m = getRand(5, 7);
        k = getRand(5, 7);
        p = 1000000007;
        fout << n << " " << m << " " << k << " " << p << endl;
        writeToFile();
        fout.close();
    }

    // data in 60%, 2 <= n <= 50, 1 <= m <= 1e6, 1 <= k <= 1e6, 1e7 <= p <= 1e9
    int two = testCases * 60 / 100;
    for (int i = one + 1; i <= two; ++i) {
        fout.open(getFileName(i));
        fout << i << endl;
        n = getRand(45, 50);
        m = getRand(100000, 1000000);
        k = getRand(999900, 1000000);
        p = getRand(10000000, 1000000000);
        fout << n << " " << m << " " << k << " " << p << endl;
        writeToFile();
        fout.close();
    }

    // data in 100%, 2 <= n <= 4, 1 <= m <= 1e6, 1 <= k <= 1e100000, 1 <= p <= 3
    for (int i = two + 1; i <= testCases; ++i) {
        fout.open(getFileName(i));
        fout << i << endl;
        n = getRand(3, 4);
        m = getRand(100000, 1000000);
        p = getRand(2, 3);
        int lenOfk = getRand(50000, 100000);
        fout << n << " " << m << " ";
        fout << getRand(1, 9);
        for (int j = 1; j < lenOfk; ++j) {
            fout << getRand(0, 9);
        }
        fout << " " << p << endl;
        writeToFile();
        fout.close();
    }

    return 0;
}
