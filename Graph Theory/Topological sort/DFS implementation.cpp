#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

vector<ll>adj[3006];
ll vis[3006];
vector<ll>ans;

void dfs(ll s)
{
    vis[s]=1;
    for(auto it:adj[s])
        if(vis[it]==0)
            dfs(it);

    ans.push_back(s);
}

void toposort(ll n)
{
    memset(vis, 0, sizeof vis);
    ans.clear();

    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
            dfs(i);
    }

    reverse(ans.begin(), ans.end());
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
    }

    toposort(n);

    for(auto i: ans)
        cout << i << " " ;

    cout << endl ;
}
