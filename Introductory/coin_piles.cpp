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
typedef tree<ll, ll, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
 
 
int main()
{
    FASTIO;
    ll t;
    cin>>t;
    while(t--)
    {
        ll a, b;
        cin>>a>>b;
        ll mx = max(a,b), mn = min(a, b);
        cout<<((a+b)%3==0 && mx/2<=mn ? "YES\n" : "NO\n");
    }
}