#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int testCases = 50;
ofstream fout;

string numToStr(int x) {
    string str;
    while (x != 0) {
        str = char('0' + x % 10) + str;
        x /= 10;
    }
    return str;
}

string getFileInName(int index) {
    return "data/" + numToStr(index) + ".in";
}

string getFileOutName(int index) {
    return "data/" + numToStr(index) + ".out";
}

LL getRand(LL l, LL r) {
    return (LL)rand() * rand() * rand() % (r - l + 1) + l;
}

void writeToFile(int fileIdx, LL l, LL r) {
    string fileInName = getFileInName(fileIdx);
    fout.open(fileInName);
    LL e5 = 1e5;
    int T = getRand(90, 100);
    int idx = getRand(1, T);
    fout << T << endl;
    for (int i = 1; i <= T; ++i) {
        int a = 0;
        if (idx != i) {
            a = getRand(1, e5);
        }
        LL n = getRand(l, r);
        fout << a << " " << n << endl;
    }
    fout.close();
    string fileOutName = getFileOutName(fileIdx);
    system(("std.exe < " + fileInName  + " > " + fileOutName).c_str());
}

int main() {
    srand(time(0));

    LL e5 = 1e5;
    LL e10 = 1e10;
    LL e11 = 1e11;

    for (int i = 1; i <= testCases; ++i) {
        if (i % 2 == 0) {
            writeToFile(i, 1, e5 - 1);
        } else {
            writeToFile(i, e10, e11 - 1);
        }
    }

    return 0;
}
