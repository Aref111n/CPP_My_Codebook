/*
An Eulerian cycle, also called an Eulerian circuit, Euler circuit, Eulerian tour, or Euler tour, is a trail which starts and ends at the same graph vertex. 
In other words, it is a graph cycle which uses each graph edge exactly once.
- A condition for euler tour is, all the vertex should be even degree.
If there are any vertex with odd degree, create a new extra vertex and connect all those.

The below implementation is based on CODEFORCES 723E
*/
#include<bits/stdc++.h>
#define  orr   ||
using namespace std;
typedef long long ll;

set<ll> adj[300];

void euler_tour(ll s)
{
    cout << s << ">";
    if(adj[s].size()==0)
        return;

    ll x = *adj[s].begin() ;
    adj[s].erase(x);
    adj[x].erase(s);
    if(s != 0 && x != 0)
        //cout << s __ x << endl;
    euler_tour(x);
}

int main()
{
    
        ll n, m;
        cin >> n >> m ;

        for(int i=0; i<m; i++)
        {
            ll a, b ;
            cin >> a >> b ;
            adj[a].insert(b);
            adj[b].insert(a);
        }

        ll cnt = 0;

        for(int i=0; i<n; i++)
        {
            if((adj[i].size())%2==0)
                cnt++;
            else
            {
                adj[0].insert(i);
                adj[i].insert(0);
            }
        }

        cout << cnt << endl;

        for(int i=0; i<n; i++)
        {
            if(adj[i].size())
                euler_tour(i);
            cout << endl;
        }
    
    return 0;
}
