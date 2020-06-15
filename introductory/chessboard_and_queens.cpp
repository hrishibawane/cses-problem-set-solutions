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
#define VS vector<string>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, ll, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

ll ans = 0;

bool isOk(VS &board, int x, int y)
{
    if(board[x][y]=='*') return false;
    
    for(int i=0; i<y; i++)
        if(board[x][i]=='q') return false;
    
    for(int i=x, j=y; i>=0 && j>=0; i--, j--)
        if(board[i][j]=='q') return false;
    
    for(int i=x, j=y; i<8 && j>=0; i++, j--)
        if(board[i][j]=='q') return false;
    
    return true;
}

bool solve(VS &board, int col)
{
    if(col>=8) return true;
    for(int i=0; i<8; i++)
    {
        if(isOk(board, i, col))
        {
            board[i][col] = 'q';
            if(solve(board, col+1)) ans++;
            board[i][col] = '.';
        }
    }
    return false;
}

int main()
{
    FASTIO;
    VS board(8);
    for(auto &i:board) cin>>i;

    solve(board, 0);
    cout<<ans<<'\n';
}
