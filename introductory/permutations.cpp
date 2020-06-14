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
    if(n<=4) 
    {
        if(n==1) cout<<"1\n";
        else if(n==4) cout<<"2 4 1 3\n";
        else cout<<"NO SOLUTION\n";
        return 0;
    }
    VLL a(n);
    ll lim = n&1 ? n/2+1 : n/2;
    ll evn = 0, odd = 1, k = 1;
    while(evn < a.size())
    {
        a[evn] = k;
        a[odd] = k+lim;
        evn+=2;
        odd+=2;
        k++;
    }
    for(auto i:a) cout<<i<<' ';
    cout<<'\n';
 
}