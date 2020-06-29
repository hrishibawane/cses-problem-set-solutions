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
#define VI vector<int>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MOD 1000000007
#define MAX 1000005
using namespace std;

bool isBp(vector<VLL> &g, VB &vis, VI &team, ll src)
{
    queue<ll> q;
    q.push(src);
    team[src] = 1;
    while(!q.empty())
    {
        ll curr = q.front();
        q.pop();
        if(vis[curr]) continue;
        vis[curr] = true;
        for(ll i=0; i<g[curr].size(); i++)
        {
            ll k = g[curr][i];
            if(team[k]==-1)
            {
                q.push(k);
                team[k] = 1-team[curr];
            }
            else if(team[k]==team[curr])
                return false;
        }
    }
    return true;
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
    VB vis(n, false);
    VI team(n, -1);
    bool flag = 1;
    for(ll i=0; i<n; i++)
    {
        if(!vis[i] && !isBp(g, vis, team, i))
        {
            flag=0;
            break;
        }
    }
    if(!flag) 
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for(auto i:team)
        cout<<(i ? 1 : 2)<<' ';
    cout<<'\n';
}
