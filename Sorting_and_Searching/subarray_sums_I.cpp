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
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


int main()
{
    FASTIO;
    ll n, sum;
    cin>>n>>sum;
    ll currsum = 0, ans = 0, k;
    unordered_map<ll, ll> prev;
    for(ll i=0; i<n; i++)
    {
        cin>>k;
        currsum += k;
        if(currsum==sum) ans++;
        
        if(prev[currsum-sum]!=0)
            ans += prev[currsum-sum];
        
        prev[currsum]++;
    }
    cout<<ans<<'\n';
}
