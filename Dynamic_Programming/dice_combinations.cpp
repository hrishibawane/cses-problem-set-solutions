#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define ull unsigned ll
#define ld long double
#define pll pair<ll, ll>
#define pb push_back
#define MOD 1000000007
#define F first
#define S second
#define VLL vector<ll>
#define VB vector<bool>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
ll solve(ll n, VLL &dp)
{
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    ll ans = 0;
    for(ll i=1; i<=6; i++)
        ans += solve(n-i, dp);
    return dp[n] = ans % MOD;
}
 
int main()
{
    ll n;
    cin>>n;
    VLL dp(n+1, -1);
    cout<<solve(n, dp)<<'\n';
}