/*
A WALK THROUGH PETERSEN GRAPH.
Google it to know about petersen graph.

This code is of a nice problem from codechef.
LINK: https://www.codechef.com/problems/PETERSEN
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> adj[10];
map<ll, char>mp;
string a, ans = "";

void init_petersen()
{
    for(int i=0; i<5; i++)
    {
        adj[i].push_back((i+1)%5);
        adj[(i+1)%5].push_back(i);

        adj[i].push_back(i+5);
        adj[i+5].push_back(i);
    }

    for(int i=5; i<10; i++)
    {
        ll k = i+2 < 10 ? i+2 : i-3 ;
        adj[i].push_back(k);
        adj[k].push_back(i);
    }

    for(int i=0; i<5; i++)
    {
        mp[i] = mp[i+5] = (char)('A' + i);
    }
}

void dfs(ll s, ll pos)
{
    if(pos >= a.size())
        return;
    ans += to_string(s);

    for(int i=0; i<adj[s].size(); i++)
    {
        if(mp[adj[s][i]] == a[pos+1])
            dfs(adj[s][i], pos+1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif
    ll n, m;
    
    init_petersen();
    
    ll test, t;
    cin >> test ;
    for(t=0; t<test; t++)
    {
        cin >> a ;
        ll p = (int)(a[0] - 'A') ;
        
        ans = "" ;
        dfs(p, 0);
        string a1 = ans ;
        
        ans = "" ;
        dfs(p+5, 0);
        string a2 = ans ;

        if(a1.size() < a.size() && a2.size() < a.size())
            cout << -1 << endl;
        else if(a1.size() < a.size())
            cout << a2 << endl;
        else if(a2.size() < a.size())
            cout << a1 << endl;
        else
        {
            if(a1[0]=='0')
                cout << a2 << endl;
            else if(a2[0]=='0')
                cout << a1 << endl;
            else if(a2 > a1)
                cout << a1 << endl;
            else
                cout << a2 << endl;

        }
    }

    return 0;

}
