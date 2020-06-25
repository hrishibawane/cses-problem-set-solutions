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
 
 
int fun(ll val, ll n, ll t, vector<ll>& arr)
{
	ll check = 0 ;
	for(int i = 0; i<n; i++)
	{
		ll x = val/arr[i] ;
		if(t - check <= x) 
			return 1;
		check += x;
	}
	return 0 ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, t;
	cin>>n>>t;
	vector<ll> arr(200005);
	for(int i = 0; i<n; i++) 
        cin>>arr[i];

	ll high = 1e18 + 9 , low = 0;
	while(high > low + 1)
    	{
		ll mid = (high + low)/2;
		if(fun(mid, n, t, arr)) 
            		high = mid;
		else 
        	    	low = mid;
	}
	if(fun(low, n, t, arr))
		cout<<low<<"\n";
	else 
		cout<<high<<"\n";
}
