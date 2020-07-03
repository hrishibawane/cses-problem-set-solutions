#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned ll
#define ld long double
#define pb push_back
#define F first
#define S second
#define PLL pair<ll, ll>
#define VLL vector<ll>
#define VB vector<bool>
#define VS vector<string>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
#define MOD 1000000007
#define MAX 100005
using namespace std;

ll n;
ll findPaths(VS &g, vector<VLL> &dp, ll i, ll j)
{
    if((i==n || j==n) || g[i][j]=='*') return 0;
    if(i==n-1 && j==n-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];

    dp[i][j] = findPaths(g, dp, i+1, j) + findPaths(g, dp, i, j+1);
    dp[i][j] %= MOD;
    return dp[i][j];
}

int main()
{
    cin>>n;
    VS g(n);
    for(auto &i:g) cin>>i;

    vector<VLL> dp(n, VLL(n, -1));
    cout<<findPaths(g, dp, 0, 0)<<'\n';
}
