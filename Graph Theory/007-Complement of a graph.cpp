/*
In graph theory, the complement or inverse of a graph G1 is a graph G2 on the same vertices such that two distinct vertices of G2 are adjacent if and only if they are not 
adjacent in G1. Given two graph G1 and G2, find if G2 is a complement pf G1.
....................................................
sample input 1:
4 4
1 2
2 3
1 3
1 4
4 3
2 4
4 3
3 2
sample output:
NO
....................................................
sample input 2:
4 10
1 2
2 3
1 4
1 3
3 2
3 3
4 4
2 1
4 1
2 3
4 2
2 4
4 3
sample output:
YES
......................................................
sample input 3:
4 10
1 2
2 3
1 4
1 3
3 2
3 3
4 4
2 1
4 1
2 3
4 3
2 4
4 3
4 4
sample output:
NO
.........................................................
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{    
    ll n, m;
    cin >> n >> m ;

    set<pair<ll, ll> > g1, g2, s ;

    for(int i=0; i<m; i++)
    {
    	int a, b;
    	cin >> a >> b ;
    	
    	if(a>b) 
    		swap(a, b);
    	
    	g1.insert({a, b});
    	s.insert({a, b});
    }

    ll p, q;
    cin >> p >> q ;

    for(int i=0; i<q; i++)
    {
    	int a, b;
    	cin >> a >> b ;
    	
    	if(a>b) 
    		swap(a, b);
    	
    	g2.insert({a, b});
    	s.insert({a, b});
    }

    if(n != p || g1.size()+g2.size()!=s.size())
    	cout << "NO" << endl;
    else
    	cout << "YES" << endl;

    return 0;
}
