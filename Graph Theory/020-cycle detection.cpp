/*
Find the number of cycles in a graph and also print them.

idea: (from a comment of Noam527 in cf blog)
------------------------------------------------
When you do dfs, you can consider vertices of 3 types; unvisited, visited but in the stack, 
or visited and finished (we called dfs on all their neighbors and returned already).
If your dfs detects a cycle, then all the cycle vertices are the type that's in the stack (they 
must have been visited, but they cannot be finished because you will find a cycle before finishing 
any vertex on it). So, one easy way to find the cycle is to maintain the stack along with a 
dfs (vector or stack, either global or passed by reference). When you find a visited neighbor, 
iterate from the back of the stack until you reach that visited node, and put all the vertices 
you iterated on in some vector, representing the cycle.
*/

#include<bits/stdc++.h>
#define  orr   ||
using namespace std;
typedef long long ll;

vector<ll> adj[300];
ll vis[300];
vector<ll>vec;
ll cnt = 0;

void dfs(ll s, ll parent)
{
    vis[s] = 1;
    vec.push_back(s);

    for(int i=0; i<adj[s].size(); i++)
    {
        if(vis[adj[s][i]]==0)
            dfs(adj[s][i], s);
        else if(adj[s][i] != parent && vis[adj[s][i]]==1)
        {
            ll p = adj[s][i] ;
            cout << p << " " ;
            ll pos = vec.size() - 1;
            while(pos >= 0 && vec[pos] != p)
            {
                cout << vec[pos] << " " ;
                pos--;
            }
            cnt++;
            cout << endl;
        }
    }

    vis[s] = 2;
    vec.pop_back();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif

    ll test ;
    //cin >> test ;
    test = 1;

    for(int tc = 0; tc< test; tc++)
    {
        ll n,  m;
        cin >> n >> m;

        for(int i=0; i<m; i++)
        {
            ll a, b ;
            cin >> a >> b ;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }        

        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0)
                dfs(i, -1);
        }

        cout << cnt << " loop found" << endl;

    }

    
    return 0;
}
