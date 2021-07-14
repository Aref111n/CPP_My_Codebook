/*
This algorithm is a single source shortest path (from one source to any other vertices). 
Pay attention that you can't have edges with negative weight.
Using std :: priority_queue
This code below prints shortest distance of each node from the source node.

Sample input 1:
-----------------
9 14
1 2 4
2 3 8 
3 4 7
4 5 9
5 6 10
6 7 2
7 8 1
8 1 8
2 8 11
8 9 7
4 6 14
9 3 2
9 7 6
3 6
Output:
1 0
2 4
3 12
4 19
5 21
6 11
7 9
8 8
9 14

------------------
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, int> > adj[3006];
int vis[3006];
int n;

void dijsktra(int v)
{
    int d[n+1];
    for(int i=1; i<=n; i++) d[i] = INT_MAX ;

    d[v] = 0;
    int u;
    priority_queue<pair<int,int>, vector<pair<int,int> >, less<pair<int,int> > > pq;
    pq.push({d[v], v});

    while(pq.size())
    {
        u = (pq.top()).second;
        pq.pop();
        vis[u] = 1;

        vector<pair<int, int> >::iterator it;
        for(it=adj[u].begin(); it!=adj[u].end(); it++)
        {
            if(d[it->first] > d[u] + it->second)
            {
                d[it->first] = d[u] + it->second ;
                pq.push({d[it->first], it->first});
            }
        }
    }

    for(int i=1; i<=n; i++)
        cout << i << " " << d[i] << endl;

    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif

    int m;
    cin >> n >> m ;

    for(int i=0; i<m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    dijsktra(1);

    return 0;
}
