#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000001;
const int maxnm = 100000;
const int testCases = 25;

struct Set {
public:
    set<int> st;
    vector<set<int>::iterator> vct;

    void init() {
        st.clear();
        vct.clear();
    }

    void add(int x) {
        pair<set<int>::iterator, bool> pr = st.insert(x);
        vct.push_back(pr.first);
        assert(st.size() == vct.size());
    }

    void del(int index) {
        assert(!st.empty());
        st.erase(vct[index]);
        vct[index] = vct.back();
        vct.pop_back();
        assert(st.size() == vct.size());
    }

    int size() {
        return vct.size();
    }
};

vector<int> multiple[maxn];
ofstream fout;
int T, n, m;
Set st;
int finalNums[maxnm], nums[maxnm], tmpNums[maxnm];
int degIn[maxn], originDegIn[maxn];
int rowIndex[maxnm], colIndex[maxnm];

void initDAG() {
    for (int i = 1; i < maxn; ++i) {
        for (int j = i + i; j < maxn; j += i) {
            multiple[i].push_back(j);
            ++originDegIn[j];
        }
    }
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

int getRand(int l, int r) {
    return rand() % (r - l + 1) + l;
}

void initDegIn() {
    memcpy(degIn, originDegIn, sizeof(degIn));
}

inline int id(int x, int y) {
    return x * m + y;
}

void randomShuffle() {
    for (int i = 0; i < n; ++i) {
        rowIndex[i] = i;
    }
    random_shuffle(rowIndex, rowIndex + n);
    for (int j = 0; j < m; ++j) {
        colIndex[j] = j;
    }
    random_shuffle(colIndex, colIndex + m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            finalNums[id(rowIndex[i], colIndex[j])] = nums[id(i, j)];
        }
    }
}

void genData() {
    if (getRand(0, 1) == 0) {
        // all in random, whether there is a solution or not
        int last = 0;
        for (int i = 0; i < n * m; ++i) {
            finalNums[i] = getRand(last + 1, (i + 1) * (maxn / maxnm));
            last = finalNums[i];
        }
        for (int i = 0; i < n * m / 3; ++i) {
            finalNums[getRand(0, n * m - 1)] = 0;
        }
        random_shuffle(finalNums, finalNums + n * m);
        return ;
    }

    st.init();
    st.add(1);
    initDegIn();
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            int index = getRand(0, st.size() - 1);
            tmpNums[i] = *st.vct[index];
            st.del(index);
            for (auto mult: multiple[tmpNums[i]]) {
                --degIn[mult];
                if (degIn[mult] == 0) {
                    st.add(mult);
                }
            }
        }
        sort(tmpNums, tmpNums + n);
        for (int i = 0; i < n; ++i) {
            nums[id(i, j)] = tmpNums[i];
        }
    }
    for (int i = 0; i < n * m / 2; ++i) {
        nums[getRand(0, n * m - 1)] = 0;
    }
    randomShuffle();
}

void writeToFile() {
    fout << n << " " << m << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j != 0) {
                fout << " ";
            }
            fout << finalNums[i * m + j];
        }
        fout << endl;
    }
}

void genDatas() {
    fout << T << endl;
}

int main() {
    srand(time(0));
    initDAG();

    // data in 20%, 1 <= T <= 10, 1 <= n,m <= 8
    int one = testCases * 20 / 100;
    for (int i = 1; i <= one; ++i) {
        fout.open(getFileName(i));
        T = 10;
        fout << T << endl;
        for (int j = 0; j < T; ++j) {
            n = 8;
            m = 8;
            genData();
            writeToFile();
        }
        fout.close();
    }

    // data in 80%, 1 <= T <= 10000, 1 <= n*m <= 100000
    int two = testCases * 80 / 100;
    for (int i = one + 1; i <= two; ++i) {
        fout.open(getFileName(i));
        T = 10;
        fout << T << endl;
        for (int j = 0; j < T; ++j) {
            n = getRand(100, 1000);
            m = getRand(maxnm / n - 10, maxnm / n);
            genData();
            writeToFile();
        }
        fout.close();
    }

    // data in last 20%, cornerCase
    for (int i = two + 1; i <= testCases; ++i) {
        fout.open(getFileName(i));
        T = 5;
        fout << T << endl;
        for (int j = 0; j < T; ++j) {
            switch (getRand(0, 2)) {
            case 0:
                n = 1;
                m = maxnm;
                break;
            case 1:
                n = maxnm;
                m = 1;
                break;
            case 2:
                n = getRand(2, 5);
                m = maxnm / n;
                break;
            }
            genData();
            writeToFile();
        }
        fout.close();
    }

    return 0;
}