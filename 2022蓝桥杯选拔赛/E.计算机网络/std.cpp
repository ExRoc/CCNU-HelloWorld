#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<vector<int> > G(N, vector<int>(3, 0));

int solve(int n) {
	if (n <= 0)
		return 0;
    vector<vector<int> > dp(n, vector<int>(3, 0));
    for (int i = 0; i < 3; i++) {
        dp[0][i] = G[0][i];
    }
    for (int i = 1; i < n; i++) {
        dp[i][0] = G[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = G[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = G[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    int ans = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    return ans;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &G[i][0], &G[i][1], &G[i][2]);
	}
	int ans = solve(n);
	cout << ans << "\n";
	return 0;
}