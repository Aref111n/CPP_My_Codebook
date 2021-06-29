/*
A graph is said to be regular or K-regular if all its vertices have the same degree K. A graph whose all vertices have degree 2 is known as a 2-regular graph.
- A regular graph can be disconnected
- 0-regular graphs have 0 edges
- A tree can't be a regular graph

Given necessary info about a graph with n vertex and m edges, find if the graph is a k-regular graph. Also print the value of k.
............................
Sample input 1:
4 6
1 2
1 3
1 4
2 3
2 4
3 4
output:
Yes
3
............................
Sample input 2:
5 0
output:
Yes
0
............................
Sample input 3:
6 5
1 2
2 3
3 1
4 5
5 6
output:
No
/*

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> adj[3006];

int main()
{   
    ll n, m;
    cin >> n >> m ;

    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    

    ll c = 0;
    for(int i=2; i<=n; i++)
    {
        if(adj[i].size()!=adj[1].size())
        {
            c = 1;
            break;
        }
    }

    if(c==0)
        cout << "Yes" << endl << adj[1].size() << endl;
    else
        cout << "No" << endl;

    return 0;
}
