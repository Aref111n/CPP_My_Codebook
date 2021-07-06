#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> adj[3006];
ll vis[3006];
vector<ll>v;
ll n;
bool f ;

void dfs(ll s, ll c)
{
    vis[s] = 1 ;
    v.push_back(s);

    if(c == n)
    {
        f = true ;
        for(int i=v.size()-1; i>=0; i--)
            cout << v[i] << " " ;
        return;
    }

    for(int i=0; i<adj[s].size(); i++)
    {
        if(vis[adj[s][i]] == 0)
            dfs(adj[s][i], c+1);
    }

    vis[s] = 0;
    v.pop_back();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif
    
    ll m;
    cin >> n >> m ;

    for(int i=0; i<m; i++)
    {
        ll a, b;
        cin >> a >> b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    f = false ;
    dfs(1, 1);
    if(f==false)
        cout << "Hamiltonian path not possible" << endl;

    return 0;

}
