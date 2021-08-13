/*
8 3
1 3 6 4 7 2 5 8
1 3 4 2
1 1 4 3
2 3 4
*/

#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;

struct seg
{
    ll prop, sum ;
};
 
seg tab[800006];
ll arr[200006];
 
void init(ll v, ll b, ll e)
{
    if(b==e)
        tab[v].sum = arr[b];
    else
    {
        ll l = v*2 , r = v*2 + 1 ;
        ll m = (b+e)/2 ;
        init(l, b, m);
        init(r, m+1, e);
        tab[v].sum = tab[l].sum + tab[r].sum ;
    } 
}
 
ll query(ll v, ll b, ll e, ll i, ll j, ll c)
{
    if(i>e || j<b) return 0;
    if(i<=b && j>=e) return tab[v].sum + c*(e-b+1) ;
    ll l = v*2 , r = v*2 + 1, m = (b+e)/2 ;
    return query(l, b, m, i, j, c + tab[v].prop) + query(r, m+1, e, i, j, c + tab[v].prop);
}
 
void update(ll v, ll b, ll e, ll i, ll j, ll val)
{
    if(j<b || i>e) return; 
    if(b >= i && e <= j)
    {
        tab[v].sum += (e-b+1)*val ;
        tab[v].prop += val ;
        return;
    }
    ll l = v*2 , r = v*2 + 1, m = (b+e)/2 ;
    update(l, b, m, i, j, val);
    update(r, m+1, e, i, j, val);
    tab[v].sum = tab[l].sum + tab[r].sum + (e-b+1)*(tab[v].prop) ;
}
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif
    ll n, q;
    cin >> n >> q;
 
    for(int i=1; i<=n; i++) 
        cin >> arr[i] ;
 
    init(1, 1, n);
 
    for(int i=0; i<q; i++)
    {
        ll b, x, y; 
        cin >> b >> x >> y ;
        
        if(b==2)
        {
            cout << query(1, 1, n, x, y, 0) << endl;
        }
        else
        {
            ll z ;
            cin >> z ;
            update(1, 1, n, x, y, z);
        }
    }
}
