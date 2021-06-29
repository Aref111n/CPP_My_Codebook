/*
Edge connectivity is the minimum number of edges whose deletion from a graph disconnects, also called the line connectivity. 
The edge connectivity of a disconnected graph is 0.
Easy way to find edge connectivity is to find the vertex with the minimum degree.
Given necessary data of a graph, find it's edge connectivity and print the edges that should be deleted. There can be multiple answer, print any.
...............................
Sample input 1:
10 15
1 2
2 3
3 4
4 5
1 5
1 6
2 8
3 9
4 10
5 7
6 9
6 10
8 7
8 10
9 7
Output:
3
1 2
1 5
1 6
...............................
Sample input 2:
5 5
1 2
2 3
3 4
4 5
5 1
Output:
2
1 2
5 1
...............................
Sample input 3:
7 15
5 6
5 7
5 3
5 2
4 5
1 5
1 4
2 1
2 3
6 6
6 6
6 6
7 7
7 7
7 7
Output:
1
5 6
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> adj[3006];
map<ll, ll> degree;

int main()
{    
    ll n, m;
    cin >> n >> m ;

    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b ;
        
        if(a != b)
        {
            degree[a]++;
            degree[b]++;
        }

        adj[a].push_back(b);
        adj[b].push_back(a);
    }    

    ll mn = INT_MAX ;
    ll min_node ;

    for(int i=1; i<=n; i++)
    {
        if(degree[i] < mn)
        {
            mn = degree[i];
            min_node = i ;
        }
    }

    cout << mn << endl;

    for(int i = 0; i < adj[min_node].size(); i++)
    {
        if(adj[min_node][i] != min_node)
            cout << min_node << " " << adj[min_node][i] << endl;
    }

    return 0;
}
