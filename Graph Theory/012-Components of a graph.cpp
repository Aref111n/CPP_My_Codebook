/*
In graph theory, a component of an undirected graph is an induced subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the rest of the graph.
In short, take every vertices that are connected by a path together in a set. The number of set you will find, is the number of components of that graph. 
A connected graph have only one component. 
A disconnected graph have more than one component. 
Given necessary data for a graph with n vertices and m edges, find the number of components of that graph. 
....................................... 
Sample input 1:
10 8
2 3
4 3
3 7
3 5
5 7
8 9
6 8
10 8
sample output:
3
explanation: if you draw this graph, you will find three disjoint set of vertices which are {1}, {2, 3, 4, 5, 7} and {6, 8, 9, 10}.
......................................
Sample input 2:
10 0
sample output:
10
explanation: all the vertices are disconnected. 
..................................... 
Sample input 3:
4 4
1 2
2 3
3 1
1 4
sample output:
1
explanation: This is a connected graph. 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[3005] ;
int vis[3005] ;

void dfs(int s)
{
    vis[s] = 1;
    
    for(int i=0; i<adj[s].size(); i++)
    {
        if(vis[adj[s][i]] == 0)
        {
            dfs(adj[s][i]) ;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++) 
    {
        int a, b;
        cin >> a >> b ;
    
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int c = 0;
    
    for(int i=1; i<n; i++) 
    {
        if(vis[i] == 0) 
        {
            c++;
            dfs(i);
        }
    }
    
    cout << c << endl ;
        
    return 0;
}
