#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int testCases = 50;
ofstream fout;
int n, m;

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

int getRand(int l, int r) {
    return (LL)rand() * rand() * rand() % (r - l + 1) + l;
}

void writeToFile(int from, int to, int l1, int r1, int l2, int r2) {
    for (int i = from; i <= to; ++i) {
        string fileInName = getFileInName(i);
        fout.open(fileInName);
        n = getRand(l1, r1);
        m = getRand(l2, r2);
        fout << n << " " << m << endl;
        fout.close();
        string fileOutName = getFileOutName(i);
        system(("std.exe < " + fileInName  + " > " + fileOutName).c_str());
    }
}

int main() {
    srand(time(0));

    // data in 10%, n = 2, 1 <= m <= 50
    int one = testCases * 10 / 100;
    writeToFile(1, one, 2, 2, 10, 50);

    // data in 20%, 2 <= n <= 1000, m = 1
    int two = testCases * 20 / 100;
    writeToFile(one + 1, two, 800, 1000, 1, 1);

    // data in 30%, 2 <= n <= 1000, 1 <= m <= 2
    int three = testCases * 30 / 100;
    writeToFile(two + 1, three, 800, 1000, 2, 2);

    // data in 50%, 2 <= n <= 5, 1 <= m <= 30
    int four = testCases * 50 / 100;
    writeToFile(three + 1, four, 4, 5, 20, 30);

    // data in 70%, 2 <= n <= 1000, 1 <= m <= 30
    int five = testCases * 70 / 100;
    writeToFile(four + 1, five, 800, 1000, 20, 30);

    // data in 100%, 2 <= n <= 1000, 1 <= m <= 50
    writeToFile(five + 1, testCases, 800, 1000, 40, 50);

    return 0;
}
