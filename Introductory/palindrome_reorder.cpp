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
    unordered_map<char, ll> um;
    for(char c:s) um[c]++;
    ll odd=0;
    string half1="", half2="";
    char oc;
    for(auto it=um.begin(); it!=um.end(); it++)
    {
        if(it->S%2) odd++, oc=it->F;
        if((odd==1 && s.length()%2==0) || odd>1)
        {
            cout<<"NO SOLUTION\n";
            return 0;
        }
        ll cnt = it->S/2;
        string chars(cnt, it->F);
        half1 = half1 + chars;
        half2 = chars + half2;
    }
    cout<<(odd ? half1+oc+half2 : half1+half2)<<'\n';
}
