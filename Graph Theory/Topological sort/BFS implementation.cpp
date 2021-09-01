#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

vector<ll>adj[3006];
ll vis[3006];
ll ind[3006];
vector<ll> ans;


void bfs(ll n)
{
    queue<ll>q;
    for(int i=1; i<=n; i++)
        if(ind[i]==0)
            q.push(i);

    while(q.size())
    {
        ll u = q.front() ;
        q.pop();
        if(ind[u]==0)
        {
            vector<ll>::iterator it;
            for(it=adj[u].begin(); it!=adj[u].end(); it++)
            {
                ind[*it]-- ;
                if(ind[*it]==0)
                    q.push(*it);
            }
        }
        ans.push_back(u);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++)
    {
        ll a, b ;
        cin >> a >> b ;
        adj[a].push_back(b);
        ind[b]++ ;
    }

    bfs(n);

    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " " ;

    cout << endl ;
}
