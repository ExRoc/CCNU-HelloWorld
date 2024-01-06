#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int maxn=1e6+10;
void solve()
{
	while("qwq")
	{
		int n;cin>>n;
		if(n==0) break;
		vector<int> a(n+1);
		vector dp(n+1,vector<int>(n+1,-1e18));
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			if(n&1) dp[i][i]=a[i];
			else dp[i][i]=-a[i];
		}
		for(int len=2;len<=n;++len)
		{
			for(int l=1,r=len;r<=n;++l,++r)
			{
				int tmp=(n-len)&1;
				if(tmp&1)
				{
					dp[l][r]=min(dp[l][r-1]-a[r],dp[l+1][r]-a[l]);
				}
				else
				{
					dp[l][r]=max(dp[l][r-1]+a[r],dp[l+1][r]+a[l]);
				}
			}
		}
		// cout<<dp[2][3]<<"!!!"<<'\n';
		if(dp[1][n]>=0) cout<<1<<'\n';
		else cout<<0<<'\n';
	}
}
signed main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0),cout.tie(0);
	int T=1; //cin>>T;
	while(T--) solve();
	return 0;
}
