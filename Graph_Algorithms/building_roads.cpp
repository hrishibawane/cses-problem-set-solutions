#include <bits/stdc++.h>
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
#define VS vector<string>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MOD 1000000007
#define MAX 1000005
using namespace std;
 
void bfs(vector<VLL> &g, VB &vis, ll curr)
{
    queue<ll> q;
    q.push(curr);
    while(!q.empty())
    {
        curr = q.front();
        q.pop();
        if(vis[curr]) continue;
        vis[curr] = true;
        for(ll i=0; i<g[curr].size(); i++)
            q.push(g[curr][i]);
    }
}
 
int main()
{
    FASTIO;
    ll n,m,u,v;
    cin>>n>>m;
    vector<VLL> g(n);
    for(ll i=0; i<m; i++)
    {
        cin>>u>>v;
        g[u-1].pb(v-1);
        g[v-1].pb(u-1);
    }
 
    VB vis(n, false);
    ll ans = 0;
    VLL res;
    for(ll i=0; i<n; i++)
    {
        if(!vis[i])
        {
            ans++;
            res.pb(i+1);
            bfs(g, vis, i);
        }
    }
    cout<<ans-1<<'\n';
    for(ll i=1; i<res.size(); i++)
        cout<<res[i-1]<<' '<<res[i]<<'\n';
}