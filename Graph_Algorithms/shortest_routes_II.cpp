#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned ll
#define ld long double
#define pb push_back
#define F first
#define S second
#define PLL pair<ll, ll>
#define VLL vector<ll>
#define VB vector<bool>
#define VI vector<int>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
#define MOD 1e9+7
#define MAX 1e9+5
using namespace std;
 
void floydWarshall(vector<VLL> &g)
{
    ll n = g.size();
    for(ll k=0; k<n; k++)
        for(ll i=0; i<n; i++)
            for(ll j=0; j<n; j++)
                if(g[i][k]<LLONG_MAX && g[k][j]<LLONG_MAX)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
 
int main()
{
    FASTIO;
    ll n,m,q,u,v,w;
    cin>>n>>m>>q;
    vector<VLL> g(n, VLL(n, LLONG_MAX));
    for(ll i=0; i<m; i++)
    {
        cin>>u>>v>>w;
        g[u-1][v-1] = min(w, g[u-1][v-1]);
        g[v-1][u-1] = min(w, g[v-1][u-1]);
    }
 
    for(ll i=0; i<n; i++)
        for(ll j=0; j<n; j++)
            if(i==j) g[i][j] = 0;
 
    floydWarshall(g);
    while(q--)
    {
        cin>>u>>v;
        cout<<(g[u-1][v-1]==LLONG_MAX ? -1 : g[u-1][v-1])<<'\n';
    }
}