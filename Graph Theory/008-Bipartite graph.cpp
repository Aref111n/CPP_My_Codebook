/*
A bipartite graph is a graph whose vertices can be divided into two disjoint and independent sets U and V such that every edge connects a vertex in U to one in V. 
Given necessary data, find if the graph is a bipartite graph. If the graph is bipartite, print the two disjoint set in two different line.
..........................................
Sample input 1:
4 4
1 2
1 3
2 4
3 4
sample output:
YES
1 4
2 3
...........................................
Sample input 2:
9 7
1 6
1 8
2 6
2 9
3 7
7 4
5 8
sample output:
YES
1 2 3 4 5
6 7 8 9
.............................................
Sample input 3:
1 0
sample output:
YES
1
.............................................
Sample input 4:
3 3
1 2
1 3
2 3
sample output:
NO
..............................................
Sample input 5:
4 0
sample output:
YES
1 2 3 4
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> adj[2005];
ll vis[2005];
ll col[2005];
vector<ll> c1, c0;

bool dfs(int s, int c)
{
	vis[s] = 1;
	col[s] = c;
	if(c==0)
		c0.push_back(s);
	else
		c1.push_back(s);

	vector<ll>::iterator it;
	for(it=adj[s].begin(); it!=adj[s].end(); it++)
	{
		if(vis[*it]==0)
		{
			if(dfs(*it, 1-c)==false)
				return false;
		}
		else if(col[s]==col[*it])
			return false;
	}
	return true;
}

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

    ll p = 1;

    for(int i=1; i<=n; i++)
    {
    	if(vis[i]==0)
    	{
    		p = dfs(i, 0);
    	}
    	if(p==0)
    		break;
    }

    if(p==1)
    {
    	cout << "YES" << endl;
    	for(int i=0; i<c0.size(); i++)
    	{
    		cout << c0[i] << " " ;
    	}
    	cout << endl;
    	for(int i=0; i<c1.size(); i++)
    	{
    		cout << c1[i] << " " ;
    	}
    	cout << endl;

    }
    else
    	cout << "NO" << endl;

    return 0;
}
