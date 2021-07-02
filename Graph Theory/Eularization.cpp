/*
Eulerization is the process of adding edges to a graph to create an Euler circuit on a graph. 
To eulerize a graph, edges are duplicated to connect pairs of vertices with odd degree. Connecting 
two odd degree vertices increases the degree of each, giving them both even degree. When two odd degree 
vertices are not directly connected, we can duplicate all edges in a path connecting the two.
.....................
Sample input 1:
4 4
1 2
2 3
3 4
2 4
output:
1
1 2
.....................
Sample input 2:
4 3
1 2
1 3
1 4
output:
2
1 2
3 4
......................
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
    vector<ll>v;
    for(int i=1; i<=n; i++)
    {
        if(degree[i]%2==1)
        {
            odd++;
            v.push_back(i);
        }
    }

    cout << odd/2 << endl;

    for(int i=0; i<v.size(); i+=2)
        cout << v[i] << " " << v[i+1] << endl;
    
    return 0;
}
