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
    ll n;
    cin>>n;
    for(ll i=1; i<=n; i++)
    {
        ll nc2 = (i*i*(i*i-1))/2;   // possible combinations in ixi
        ll attack = 4*(i-1)*(i-2);   // find boards of 2x3 or 3x2
        cout<<nc2-attack<<'\n';
    }
}