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
    ll n;
    cin>>n;
    vector<pll> a(n);
    for(auto &i:a)
        cin>>i.F>>i.S;
    
    sort(a.begin(), a.end());
    ll ans = 0, time = 0;
    for(auto i:a)
    {
        time += i.F;
        ans += i.S - time;
    }
    cout<<ans<<'\n';
}
