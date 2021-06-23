/*
A complete Bipartite graph is a special case of Bipartite graph. Suppose there are two disjoint Set A and B. 
each elements of A must have a node with all the elements of B and vice versa. 
Then we can call it a Complete bipartite graph. 
Given n vertices from 1 to n, and m edges, find whether is it a Complete Bipartite graph? If "YES", print the elements of the both sets. 
............................................
Sample input 1 
8 15
1 6
2 6
3 6
4 6
5 6
1 7
2 7
3 7
4 7
5 7
1 8
2 8
3 8
4 8
5 8
sample output:
YES
1 2 3 4 5
6 7 8
.............................................
Sample input 2:
8 16
1 6
2 6
3 6
4 6
5 6
1 7
2 7
3 7
4 7
5 7
1 8
2 8
3 8
4 8
5 8
4 5
sample output:
NO
............................................. 
Sample input 3:
2 1
1 2
Sample output:
YES
1
2
.............................................
Sample input 4:
6 5
1 2
3 5
3 6
4 5
4 6
sample output:
NO
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>adj[3005];
vector<ll> v1, v2;

bool isCompleteBP(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(adj[i] == v1 || adj[i] == v2)
            continue;
        else if(v1.size() == 0)
            v1 = adj[i] ;
        else if(v2.size() == 0)
            v2 = adj[i] ;
        else
            return false;

    }

    return true;
}
int main()
{
    int n, m;
    cin >> n >> m ;

    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(isCompleteBP(n) == true)
    {
        cout << "Yes" << endl;

        for(int j=0; j<v1.size(); j++)
            cout << v1[j] << endl;
        cout << endl ;

        for(int j=0; j<v2.size(); j++)
            cout << v2[j] << endl;
        cout << endl ;
    }
    else
    {
        cout << "NO" << endl ;
    }

    return 0;
}
