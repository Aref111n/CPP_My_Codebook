ll etf(ll n)
{
    ll i;
    double res = n;

    for(i=2; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            while(n % i == 0)
                n /= i;                
            res *= (1.0 - (1.0/ (double)i));
        }
    }
    if(n>1)
        res *= (1.0 - (1.0/(double)n));
    return (ll)res;
}
