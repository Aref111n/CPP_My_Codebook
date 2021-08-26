#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;
 
ll tab[800006];
ll arr[200006];
 
void init(ll v, ll b, ll e)
{
    if(b==e)
        tab[v] = arr[b];
    else
    {
        ll l = v*2 , r = v*2 + 1 ;
        ll m = (b+e)/2 ;
        init(l, b, m);
        init(r, m+1, e);
        tab[v] = min(tab[l], tab[r]) ;
    } 
}
 
ll query(ll v, ll b, ll e, ll i, ll j)
{
    if(i>e || j<b) return 1e18;
    if(i<=b && j>=e) return tab[v] ;
    ll l = v*2 , r = v*2 + 1, m = (b+e)/2 ;
    return min(query(l, b, m, i, j), query(r, m+1, e, i, j));
}
 
void update(ll v, ll b, ll e, ll i, ll val)
{
    if(i<b || i>e) return; 
    if(b==i && e==i)
    {
        tab[v] = val ;
        return;
    }
    ll l = v*2 , r = v*2 + 1, m = (b+e)/2 ;
    update(l, b, m, i, val);
    update(r, m+1, e, i, val);
    tab[v] = tab[l] + tab[r] ;
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
        ll x, y; 
        cin >> x >> y ;
        
        cout << query(1, 1, n, x, y) << endl;
    }
}
