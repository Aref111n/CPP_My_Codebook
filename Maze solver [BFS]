/*
This code implements "Lee Algorithm" to solve this problem.
To know more about Lee algorithm: https://en.wikipedia.org/wiki/Lee_algorithm
*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define endl "\n"
#define    rep(X,Y)     for(X=0;X<Y;X++)
#define    rep1(X,Y)    for(X=1;X<=Y;X++)
#define    rrep(X,Y)    for(X=Y-1;X>=0;X--)
#define    rrep1(X,Y)   for(X=Y;X>=1;X--)
#define ml ll T,g; cin>>T; for(g=0;g<T;g++)
#define case "Case "<<g+1<<":"
#define sf(T) scanf("%lld",&T)
#define pf(T) printf("%lld\n",T)
#define FastRead                      \
                                    ios_base::sync_with_stdio(false); \
                                    cin.tie(0);
#define pi acos(-1)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

bool vis[300][300];
ll level[300][300] , n;
string a[255];

void bfs(pair<ll, ll>s )
{
    queue<pair<ll, ll> >q;
    q.push(s);

    vis[s.first][s.second] = 1;
    level[s.first][s.second] = 1;

    while(q.size()!=0)
    {
        pair<ll, ll>p;
        p = q.front();
        q.pop();

        ll x = p.first;
        ll y = p.second;

        if(x+1<n && a[x+1][y]!='O' && vis[x+1][y] == 0)
        {
            vis[x+1][y] = 1;
            q.push({x+1, y});
            level[x+1][y] = level[x][y] + 1;
        }
        if(y+1<n && a[x][y+1]!='O' && vis[x][y+1] == 0)
        {
            vis[x][y+1] = 1;
            q.push({x, y+1});
            level[x][y+1] = level[x][y] + 1;
        }
        if(y-1>=0 && a[x][y-1]!='O' && vis[x][y-1] == 0)
        {
            vis[x][y-1] = 1;
            q.push({x, y-1});
            level[x][y-1] = level[x][y] + 1;
        }
        if(x-1>=0 && a[x-1][y]!='O' && vis[x-1][y] == 0)
        {
            vis[x-1][y] = 1;
            q.push({x-1, y});
            level[x-1][y] = level[x][y] + 1;
        }


    }
}
void bfs1(pair<ll, ll>s)
{
    ll x = s.first;
    ll y = s.second;
    
    if(level[x][y]-1 == level[x-1][y])
    {
        a[x - 1][y] = '+';
        bfs1({x - 1, y});
    }
    else if(level[x][y]-1 == level[x][y-1])
    {
        a[x][y - 1] = '+';
        bfs1({x, y - 1});
    }
    else if(level[x][y]-1 == level[x+1][y])
    {
        a[x + 1][y] = '+';
        bfs1({x + 1, y});
    }
    else if(level[x][y]-1 == level[x][y+1])
    {
        a[x][y + 1] = '+';
        bfs1({x, y + 1});
    }

}
int main()
{
    FastRead
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n , i ,j;
    cin >> n;

    rep(i , n)
    cin >> a[i];

    pair<ll, ll>f, e;

    rep(i, n)
    {
        rep(j, n)
        {
            if(a[i][j] == 'X')
                f = {i, j};
            if(a[i][j] == '@')
                e = {i, j};
        }
    }

    bfs(f);

    //bfs1(e);
    rep(i, n)
    {
        rep(j, n)
        {
            cout << level[i][j];
        }
        cout<<endl;
    }

    return 0;
}
