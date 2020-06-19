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
    ll n,x,k;
    cin>>n>>x;
    multimap<ll, ll> m;
    for(ll i=0; i<n; i++)
        cin>>k, m.insert({k, i+1});

    for(auto p:m)
    {
        auto it = m.find(x-p.F);
        if(it!=m.end() && it->S!=p.S)
        {
            cout<<p.S<<' '<<it->S<<'\n';
            return 0;
        }
    }
    cout<<"IMPOSSIBLE\n";
}
