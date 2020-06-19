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
    ll x, n;
    cin>>x>>n;
    set<ll> pts = {0, x};
    multiset<ll> lens = {x};
    while(n--)
    {
        ll k;
        cin>>k;
        auto it = pts.insert(k).F;
        ll right = *next(it);
        ll left = *prev(it);
        lens.erase(lens.find(right-left));
        lens.insert(right-k);
        lens.insert(k-left);
        cout<<*(lens.rbegin())<<' ';
    }
    cout<<'\n';
}
