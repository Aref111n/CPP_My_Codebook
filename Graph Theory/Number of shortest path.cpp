/*
source: https://www.baeldung.com/cs/graph-number-of-shortest-paths
problem: https://atcoder.jp/contests/abc211/tasks/abc211_d
*/

//Solve here...
vector<pair<int, int> > adj[300006];
ll path[300005];
int n;

ll dijsktra(int v)
{
    int d[n+1];
    for(int i=1; i<=n; i++) d[i] = INT_MAX ;

    d[v] = 0;
    path[v] = 1;
    int u;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push({d[v], v});

    while(pq.size())
    {
        u = (pq.top()).second;
        pq.pop();

        vector<pair<int, int> >::iterator it;
        for(it=adj[u].begin(); it!=adj[u].end(); it++)
        {

            if(d[it->first] > d[u] + it->second)
            {
                d[it->first] = d[u] + it->second ;
                pq.push({d[it->first], it->first});
                path[it->first] = path[u];
            }
            else if(d[it->first] == d[u] + it->second)
            {
                path[it->first] = (path[it->first] + path[u])%mod ;
            }
        }
    }

    return path[n];
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
        int a, b, w=1;
        cin >> a >> b ;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    cout << dijsktra(1) << endl;

    return 0;
}

 
