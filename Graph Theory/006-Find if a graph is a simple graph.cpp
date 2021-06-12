/*
Simple graph has no self loops or multiple edges. 
Given n= number of vertex and m=number of edges and in the next m line, all the edges a b, find if the graph is a simple graph.
...........................
sample input 1:
6 7
1 2
1 4
2 4
2 1
5 6
3 2
6 5
sample output 1:
NO
..........................
sample input 2:
8 8
1 5
2 4
3 3
6 7
2 5
8 6
6 6
6 1
sample output 2:
NO
............................
sample input 3:
4 4
1 2
2 3
1 3
1 4
sample output 3:
YES
............................
sample input 4:
4 1
1 2
sample output 4:
YES
*/
#include<bits/stdc++.h>
using namespace std;
#define len(n) (long long)log10(n)+1.0000000001
typedef long long ll;

int main()
{   
    ll n, m;
    cin >> n >> m ;

    set<pair<ll, ll> > s;

    for(int i=0; i<m; i++)
    {
    	int a, b;
    	cin >> a >> b ;
    	if(a == b)
    		continue;
    	else
    	{
    		if(a>b) 
    			swap(a, b);

    		s.insert({a, b});
    	}
    }

    if(s.size() == m)
    	cout << "YES" << endl;
    else
    	cout << "NO" << endl;
    return 0;
}
