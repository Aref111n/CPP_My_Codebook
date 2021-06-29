#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll>adj[3006];

ll find_chromatic(ll n)
{
    ll color[n+1];
    set <ll> cnt;
    memset(color, 0, sizeof color);

    color[1] = 1;
    cnt.insert(1);

    bool painter[n+1];
    memset(painter, false, sizeof painter);

    for(int u=2; u<=n; u++)
    {
        vector<ll>::iterator it;

        for(it=adj[u].begin(); it!=adj[u].end(); it++)
        {
            if(color[*it])
                painter[color[*it]] = true ;
        }

        int p;
        for(p=1; p<=n; p++)
        {
            if(painter[p]==false)
                break;
        }

        color[u] = p ;
        cnt.insert(p);

        for(it=adj[u].begin(); it!=adj[u].end(); it++)
        {
            painter[color[*it]] = false;
        }

    }

    return cnt.size();

}

int main()
{
    ll n, m;
    cin >> n >> m ;

    for(int i=0; i<m; i++)
    {
        ll a, b;
        cin >> a >> b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << find_chromatic(n) << endl;

    return 0;
}
