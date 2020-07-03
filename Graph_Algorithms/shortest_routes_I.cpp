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
#define MAX 1e5+5
using namespace std;

void djikstra(vector<vector<PLL>> &g, VLL &dist, VB &vis)
{
    priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while(!pq.empty())
    {
        PLL curr = pq.top();
        pq.pop();
        ll uw = curr.F, u = curr.S;
        if(vis[u]) continue;
        vis[u] = true;
        // cout<<u<<' '<<uw<<'\n';
        for(ll i=0; i<g[u].size(); i++)
        {
            ll v = g[u][i].F, vw = g[u][i].S;
            if(dist[u] + vw < dist[v])
            {
                dist[v] = dist[u] + vw;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    FASTIO;
    ll n,m,u,v,w;
    cin>>n>>m;
    vector<vector<PLL>> g(n);
    for(ll i=0; i<m; i++)
    {
        cin>>u>>v>>w;
        g[u-1].pb({v-1, w});
    }

    VLL dist(n, LLONG_MAX);
    VB vis(n, false);
    djikstra(g, dist, vis);
    for(auto d:dist) cout<<d<<' ';
    cout<<'\n';
}
