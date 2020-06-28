#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define ull unsigned ll
#define ld long double
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define VLL vector<ll>
#define VB vector<bool>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
#define MOD 1000000007
#define MAX 1000005
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ll n, x;
    cin>>n>>x;
    VLL a(n), dp(x+1);
    for(auto &i:a) cin>>i;
    dp[0] = 0;
    for(int i=1; i<=x; i++)
    {
        dp[i] = INT_MAX;
        for(auto c:a)
            if(i-c>=0) dp[i] = min(dp[i], dp[i-c]+1);
    }
    cout<<(dp[x]==INT_MAX ? -1 : dp[x])<<'\n';
}
