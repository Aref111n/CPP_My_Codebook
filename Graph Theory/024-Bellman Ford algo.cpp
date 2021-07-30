#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct edge
{
    ll s, d, w;
};
ll n, m, sc, des ;
edge adj[305];

ll bellmen_ford()
{
    int i, j ;
    ll dis[10005];
    for(i=1; i<=n; i++) dis[i]=1e9 ;

    dis[sc] = 0 ;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            ll u = adj[j].s ;
            ll v = adj[j].d ;
            ll w = adj[j].w ;

            if(dis[u]!=1e9 && dis[u] + w < dis[v])
            {
                dis[v] = dis[u]+w;
            }
        }
    }

    return dis[des];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif
    
    ll test_cases ;
    cin >> test_cases ;
    while(test_cases--)
    {
        cin >> n >> m >> sc >> des ;

        for(int i=1; i<=m; i++)
            cin >> adj[i].s >> adj[i].d >> adj[i].w ;

        cout << bellmen_ford() << endl;
    }
    return 0;
}
