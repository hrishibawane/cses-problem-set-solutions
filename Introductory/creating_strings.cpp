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
    string s;
    cin>>s;
    set<string> st;
    sort(s.begin(), s.end());
    do
    {
        st.insert(s);
    } while(next_permutation(s.begin(), s.end()));

    cout<<st.size()<<'\n';
    for(auto k:st) cout<<k<<'\n';
}
