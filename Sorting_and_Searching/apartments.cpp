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
    ll n,m,k;
    cin>>n>>m>>k;
    VLL a(n), b(m);
    for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
 
    ll j=0, ans=0;
    for(ll i=0; i<n; i++)
    {
        while(j<m && b[j]<a[i]-k)
            j++;
        if(j<m && b[j]>=a[i]-k && b[j]<=a[i]+k)
            ans++, j++;
    }
    cout<<ans<<'\n';
}