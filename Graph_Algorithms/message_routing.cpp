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

ll bfs(vector<VLL> &g, VLL &path)
{
    ll n = g.size();
    VB vis(n, false);
    VLL dist(n, INT_MAX);
    queue<ll> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty())
    {
        ll curr = q.front();
        q.pop();
        if(vis[curr]) continue;
        vis[curr] = true;
        for(ll i=0; i<g[curr].size(); i++)
        {
            ll k = g[curr][i];
            q.push(k);
            if(dist[curr]+1 < dist[k])
            {
                path[k] = curr;
                dist[k] = dist[curr]+1;
            }
            if(k==n-1) return dist[k];
        }
    }
    return -1;
}

int main()
{
    FASTIO;
    ll n,m,u,v;
    cin>>n>>m;
    vector<VLL> g(n);
    VLL path(n, -1);
    for(ll i=0; i<m; i++)
    {
        cin>>u>>v;
        g[u-1].pb(v-1);
        g[v-1].pb(u-1);
    }

    ll ans = bfs(g, path);
    if(ans==-1)
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    cout<<ans+1<<'\n';
    
    VLL res;
    ll x = n-1;
    while(x!=-1)
    {
        res.pb(x+1);
        x = path[x];
    }
    for(ll i=res.size()-1; i>=0; i--)
        cout<<res[i]<<' ';
    cout<<'\n';
}
