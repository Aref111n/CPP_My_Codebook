/*
Apying BFS is practically a good way to find the shortest path for two given nodes.
You just need a "count" array or map for every vertex to keep tracing the levels. 
while you found your destination vertex on the front of the queue, return it's count value. 
Given a graph having n vertices, m edges, starting from node s and destination at node d.
Find the shortest path to reach d from s if you can reach d, otherwise print -1.
................................ 
Sample input 1:
4 2 1 4
1 2
3 4
sample output:
-1
................................ 
Sample input 2:
4 4 1 4
1 2
2 3
4 3
4 2
sample output:
2
explanation: shortest path is 1>2>4
................................
Sample input 3:
4 4 1 4
1 2
2 4
1 3
3 4
sample output:
2
explanation: 1>2>4 or 1>3>4
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> adj[3005] ;
vector<ll>::iterator it;
int vis[3005] ;
map<ll, ll>cnt ;

int bfs(ll s, ll d)
{
    queue<ll>q;
    q.push(s);
    vis[s] = 1;
    cnt[s] = 0;

    while(q.size()!=0)
    {
        int u = q.front();
        if(u == d)
            return cnt[d];
        q.pop();
        for(it = adj[u].begin() ; it!= adj[u].end() ; it++)
        {
            if(vis[*it]==0)
            {
                cnt[*it] = cnt[u] + 1;
                q.push(*it);
                vis[*it] = 1;
            }
        }
    }

    return 0 ;
}
int main()
{
    ll n, m, s, d;
    cin >> n >> m >> s >> d;

    for(int i=0; i<m; i++)
    {
        ll a, b;
        cin >> a >> b ;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll k = bfs(s, d);
    if(k == 0)
        cout << "-1" << endl ;
    else
        cout << k << endl ;

    return 0;
}
