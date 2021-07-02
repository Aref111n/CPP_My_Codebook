/*
 Eulerian Path is a path in graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.
 You can visit each edge only once but each vertex as many time as possible.
 - If all the vertex of the graph is even degree, then eulerian path and eulerian circuit possible.
 - If there are two vertex with odd degree, then eulerian path possible but eulerian circuit not possible.
 - If there are more then 2 vertex with odd degree, then nor eulerian path or eulerian circuit is possible.
 - A graph doesnt contain odd number of vertex with odd degree.
 ............................
Sample input 1:
4 5
1 2
2 3
3 4
2 4
1 4
output:
YES
Not a circuit
.............................
Sample input 2:
4 5
1 2
2 3
3 4
2 4
2 1
output:
YES
circuit
..............................
Sample input 3:
4 3
1 2
1 3
1 4
output:
NO
*/

#include<bits/stdc++.h>
#define  orr   ||
using namespace std;
typedef long long ll;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif
    
    ll n, m, k;
    cin >> n >> m ;

    map<ll, ll>degree;

    for(int i=0; i<m; i++)
    {
        ll a, b ;
        cin >> a >> b ;
        degree[a]++;
        degree[b]++;
    }

    ll odd = 0;
    for(int i=1; i<=n; i++)
    {
        if(degree[i]%2==1)
            odd++;
    }

    if(odd>2)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;

        if(odd==0)
            cout << "circuit" << endl;
        else
            cout << "Not a circuit" << endl;
    }
    
    return 0;
}
