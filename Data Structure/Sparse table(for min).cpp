/*
Sparse Table is a data structure, that allows answering range queries.
The only drawback of this data structure is, that it can only be used on immutable arrays. 
This means, that the array cannot be changed between two queries. If any element in the array changes,
the complete data structure has to be recomputed.

To get sparse table more clearly: https://www.youtube.com/watch?v=0jWeUdxrGm4
this code is the solution of: https://www.spoj.com/problems/RMQSQ/
*/



#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll L = 17 ;
ll table[100000][17] ;
ll Log[100000] ;

void BuildST(ll n, ll a[])
{
    Log[1] = 0;
    for(int i=2; i<=n; i++)
        Log[i] = Log[i/2] + 1;

    for(int i=0; i<n; i++)
        table[i][0] = a[i] ;

    for(int k=1; k<L; k++)
        for(int i=0; i+(1<<k)-1 < n; i++)
            table[i][k] = min(table[i][k-1], table[i+(1<<(k-1))][k-1]);
}

ll query(ll L, ll R)
{
    ll len = R - L + 1 ;
    ll k = Log[len] ;
    return min(table[L][k], table[R-(1<<k)+1][k]);
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif
 
 
    ll i,j,k;
    ll n;
    cin >> n ;
    ll a[n+1];
    for(int i=0; i<n; i++) cin>>a[i];
    BuildST(n, a);
    ll q;
    cin >> q;
    for(int i=0; i<q; i++)
    {
        ll l, r;
        cin >> l >> r ;
        cout << query(l, r) << endl;
    }

    return 0;
}
