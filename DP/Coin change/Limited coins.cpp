ll coin(ll coins[], ll count[], ll sum) 
{

    ll i, j, n = 3;
    ll dp[n+1][sum+1] ;
    rep(i, n+1)
    {
        rep(j, sum+1)
            dp[i][j]= 0 ;
    }

    ll ret = 0;
    dp[0][0] = 1;
    rep1(j, n) 
    {
        for (int i = 0; i <= sum; i++) {
    dp[j][i] += dp[j-1][i];
    }

    for (int k = 1; k <= count[j - 1]; k++) 
    {
        int initial = coins[j - 1] * k;
        for (int i = initial; i <= sum; i++) 
        {
            dp[j][i] += dp[j-1][i - initial];
        }
    }
}

    return dp[n][sum];

}
