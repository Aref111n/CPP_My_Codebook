/*
You have n types of coin coins[1], coins[2],...,coins[n] and each of them are of limited number.
The amount of each coins are count[1], count[2],....count[n].
In how many ways you can change m unit of money?
*/
ll coin(ll n, ll coins[], ll count[], ll m) 
{

    ll i, j, n ;
    ll dp[n+1][m+1] ;
    rep(i, n+1)
    {
        rep(j, m+1)
            dp[i][j]= 0 ;
    }

    ll ret = 0;
    dp[0][0] = 1;
    rep1(j, n) 
    {
        for (int i = 0; i <= m; i++) {
    dp[j][i] += dp[j-1][i];
    }

    for (int k = 1; k <= count[j - 1]; k++) 
    {
        int initial = coins[j - 1] * k;
        for (int i = initial; i <= m; i++) 
        {
            dp[j][i] += dp[j-1][i - initial];
        }
    }
}

    return dp[n][m];

}
