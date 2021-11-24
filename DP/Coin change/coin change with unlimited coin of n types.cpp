/*
Given n types of coin a[1], a[2], .... a[n].
In how many ways you can change m unit of money?
*/
ll coin(ll a[], ll n, ll m)
{
    ll dp[m+1], i, j;
    memset(dp, 0, sizeof dp);
    dp[0]=1;
    for(i=0; i<n; i++)
    {
        for(j=a[i]; j<=m; j++)
        {
            dp[j] += dp[j-a[i]]; 
        }
    }
    return dp[m] ;
}
