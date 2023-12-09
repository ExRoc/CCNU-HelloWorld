#include <bits/stdc++.h>
using namespace std;

const int testCases = 50;
ofstream fout;

int getRand(int l, int r) {
    return rand() % (r - l + 1) + l;
}

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

int main() {
    srand(time(0));

    // data in 10%, 1 <= n <= 2, 1 <= m <= 100
    int one = testCases * 10 / 100;
    for (int i = 1; i <= one; ++i) {
        fout.open(getFileName(i));
        switch (getRand(1, 3)) {
        case 1:
            fout << "1 " << getRand(70, 100) << endl;
            break;
        case 2:
            fout << "2 " << getRand(40, 50) * 2 << endl;
            break;
        case 3:
            fout << "2 " << getRand(40, 50) * 2 - 1 << endl;
            break;
        }
        fout.close();
    }

    // data in 20%, 1 <= n <= m <= 100
    int two = testCases * 20 / 100;
    for (int i = one + 1; i <= two; ++i) {
        fout.open(getFileName(i));
        int n = getRand(10, 70);
        int m = getRand(n, 100);
        fout << n << " " << m << endl;
        fout.close();
    }

    // data in 100%, 1 <= n <= m <= 5000
    int three = testCases;
    for (int i = two + 1; i <= three; ++i) {
        fout.open(getFileName(i));
        int n = getRand(2450, 2550);
        int m = getRand(4900, 5000);
        fout << n << " " << m << endl;
        fout.close();
    }

    return 0;
}
