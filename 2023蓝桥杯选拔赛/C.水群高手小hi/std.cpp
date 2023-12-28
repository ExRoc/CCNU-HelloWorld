#include<bits/stdc++.h>
using namespace std;

int main() {
    string str, ss;
    cin >> str;
    for (char ch: str) {
        ss += str[0];
    }
    int ans = (str.length() - 1) * 9 + 1 + (str[0] - '0');
    if (str >= ss) {
        cout << ans << endl;
    } else {
        cout << ans - 1 << endl;
    }

    return 0;
}
