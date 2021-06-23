/*
Degree of a vertex means all the edges that connects with that vertex. 
Self loops have 2 degree. 
Given necessary data for a graph with n vertex and m edges, find the maximum degree of a graph. 
............................. 
Sample input 1:
5 6
2 3
3 4
4 4
5 6
1 4
2 6
Sample output:
4
..............................
Sample input 2:
6 5
1 2
1 3
1 4
1 5
1 1
Sample output:
6
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int, int> degree ;
int main()
{
    int n, m, mx = 0;
    cin >> n >> m ;

    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b ;
        degree[a]++ ;
        degree[b]++ ;
        mx = max(degree[a], mx) ;
        mx = max(degree[b], mx) ;
    }
    
    cout << mx << endl ;

    
    return 0;
}
