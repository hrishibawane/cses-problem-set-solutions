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

bool check(VLL &a, ll mid, ll k)
{
    ll sum = 0, cnt = 0;
    for(ll i=0; i<a.size(); i++)
    {
        if(a[i]>mid) return false;

        sum += a[i];
        if(sum>mid)
        {
            cnt++;
            sum = a[i];
        }
    }
    cnt++;
    return cnt<=k;
}

int main()
{
    FASTIO;
    ll n, k;
    cin>>n>>k;
    ll low = 1, high = 0;
    VLL a(n);
    for(auto &i:a)
        cin>>i, high+=i;
    
    ll ans = 0;
    while(low<=high)
    {
        ll mid = (low+high)/2;
        if(check(a, mid, k))
        {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout<<ans<<'\n';
}

