#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;

vector<pll> adj[100006];
ll vis[100006];

ll prims(ll n)
{
    ll src = 1;
    priority_queue<pll, vector<pll>, greater<pll> >pq;
    ll i,u,v,w,sum=0,j,p;
    for(i=1;i<=n-1;i++)
    {
        u=src;
        vis[src]=1;

        for(j=0;j<adj[u].size();j++)
        {
            v=adj[u][j].first;
            w=adj[u][j].second;
            if(vis[v]==0)
            {
                pq.push({w, v});
            }
        }

        while(vis[src])
        {
            pll T=pq.top();
            pq.pop();
            src=T.second;
            p=T.first;
        }

        sum += p ;
    }

    return sum ;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif
    
    ll n, m;
    cin >> n >> m ;
    for(int i=0; i<m; i++)
    {
        ll a, b, w ;
        cin >> a >> b >> w ;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    cout << prims(n);

}
