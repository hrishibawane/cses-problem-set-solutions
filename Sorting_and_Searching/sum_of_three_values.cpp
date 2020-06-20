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
    ll n, x;
    cin>>n>>x;
    vector<pll> a(n);
    for(ll i=0; i<n; i++)
    {
        cin>>a[i].F;
        a[i].S = i;
    }
    sort(a.begin(), a.end());
    bool flag=0;
    for(ll i=0; i<n-2; i++)
    {
        ll p = i+1, q = n-1;
        while(p<q)
        {
            ll sum = a[i].F+a[p].F+a[q].F;
            if(sum==x && a[i].S!=a[p].S && a[p].S!=a[q].S)
            {
                cout<<a[i].S+1<<' '<<a[p].S+1<<' '<<a[q].S+1<<'\n';
                flag=1;
                break;
            }
            else if(sum<x) p++;
            else q--;
        }
        if(flag) break;
    }
    if(!flag) cout<<"IMPOSSIBLE\n";
}