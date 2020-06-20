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
 
struct Comp {
    bool operator()(const pll &a, const pll &b)
    {
        return a.F > b.F;
    }
};
 
int main()
{
    FASTIO;
    ll n;
    cin>>n;
    vector<VLL> arr(n, VLL(3));
    for(ll i=0; i<n; i++)
    {
        cin>>arr[i][0]>>arr[i][1];
        arr[i][2] = i;
    }
 
    sort(arr.begin(), arr.end());
    priority_queue<pll, vector<pll>, Comp> pq;
    ll ans = 0, room = 1;
    VLL rooms(n);
    for(ll i=0; i<n; i++)
    {
        ll a = arr[i][0], b = arr[i][1], r;
        if(!pq.empty() && pq.top().F<a) 
        {
            r = pq.top().S;
            pq.pop();
        }
        else r = (ll)pq.size()+1;
 
        pq.push({b, r});
        ans = max(ans, (ll)pq.size());
        rooms[arr[i][2]] = r;
    }
    cout<<ans<<'\n';
    for(auto i:rooms) cout<<i<<' ';
    cout<<'\n';
}