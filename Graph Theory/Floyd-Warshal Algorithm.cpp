/*
Floyd-Warshal algorithm is an all-pairs shortest path algorithm using dynamic programming.
6 7
1 2 3
1 3 3
3 4 1
4 1 1
5 6 3
2 6 6
3 5 9
find shortest distance between any two node:
shortest path between 3 and 6 is 11
shortest path between 3 and 1 is 2
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll dist[1006][1006];
void floydw()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]) ;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif

    ll m;
    cin >> n >> m ;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == j)
                dist[i][j] = 0 ;
            else
                dist[i][j] = 1e18 ;
        }
    }

    for(int i = 1; i<=m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w ;
        dist[a][b] = w ;
        dist[b][a] = w ;
    }

    floydw();

    cout << dist[3][6] << endl;

    return 0;
}

