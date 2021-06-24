/*
A complete graph is a graph with N vertices and an edge between every two vertices.
There are no loops. Every two vertices share exactly one edge.
If the number of vertex in a complete graph is n, then there are n(n-1)/2 edges possible.
Given the input of a graph with n vertex and m edges, find if the graph is a complete graph. 
...................... 
Sample input 1:
4 6
1 2
2 3
3 4
1 3
1 4
2 4
Sample output:
YES
...................... 
Sample input 2:
4 6
1 2
2 3
3 4
2 1
1 4
2 4
Sample output:
NO
......................
Sample input 3:
4 6
1 2
2 3
3 4
2 2
1 4
2 4
Sample output:
NO
....................... 
Sample input 4:
1 0
Sample output:
YES
....................... 
Sample input 5:
2 1
1 2
Sample output:
YES
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    
    set<pair<int, int> > s;
    
    for(int i=0; i<m; i++) 
    {
        int a, b;
        cin >> a >> b ;
        
        if(a == b) 
            continue;
        if(b>a) 
            swap(a, b) ;
        
        s.insert({a, b}) ;
    }
    
    if(s.size() == m && n*(n-1)/2 == m)
        cout << "YES" << endl ;
    else
        cout << "NO" << endl ;
            
    return 0;
}
