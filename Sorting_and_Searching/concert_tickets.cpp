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
    ll n,m,x;
    cin>>n>>m;
    multiset<ll, greater<ll>> s;
    for(ll i=0; i<n; i++)
        cin>>x, s.insert(x);
    
    while(m--)
    {
        cin>>x;
        auto lb = s.lower_bound(x);
        if(lb!=s.end()) 
            cout<<*lb<<'\n', s.erase(lb);
        else cout<<"-1\n";
    }

}
