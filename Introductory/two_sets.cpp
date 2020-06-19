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
    ll sum = 0;
    for(ll i=1; i<=n; i++) sum+=i;
 
    if(sum%2)
    {
        cout<<"NO\n";
        return 0;
    }
 
    VB done(n+1, false);
    ll k=0, i=n;
    sum/=2;
    while(sum>0)
    {
        k++;
        if(sum>=i)
        {
            sum -= i;
            done[i--] = true;
        }
        else 
        {
            done[sum] = true;
            sum = 0;
        }
    }
    cout<<"YES\n"<<k<<'\n';
    for(ll i=1; i<=n; i++)
        if(done[i]) cout<<i<<' ';
    
    cout<<'\n'<<n-k<<'\n';
    for(ll i=1; i<=n; i++)
        if(!done[i]) cout<<i<<' ';
 
    cout<<'\n';
 
}