ll nCr(ll n, ll r) {
    if(r<n-r) r=n-r ;
    ll ans=1;
    for(int i=0; i<n-r; i++)
        ans = (ans*(n-i))/(i+1) ;
    return ans ;
}
