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
#define VI vector<int>
#define VB vector<bool>
#define VS vector<string>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
#define MOD 1000000007
#define MAX 100005
using namespace std;

// Top-down doesnt get accepted
int main()
{
    FASTIO;
    int n, x;
    cin>>n>>x;
    VI price(n), pages(n);
    vector<VI> dp(n+1, VI(x+1, 0));
    for(auto &i:price) cin>>i;
    for(auto &i:pages) cin>>i;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=x; j++)
        {
            if(price[i-1]>j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], pages[i-1] + dp[i-1][j-price[i-1]]);
        }
    }

    cout<<dp[n][x]<<'\n';
}
