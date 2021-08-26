//BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll>prime;
ll N=50000000;
bool sieve[50000000]={0};
void primesieve()
{
    ll i;
    sieve[0]=sieve[1]=1;
        prime.push_back(2);
    for(i=4;i<N;i+=2)
        sieve[i]=1;
    ll sq=sqrt(N);
    for(i=3;i<sq;i+=2)
    {
        if(sieve[i]==0)
        {
            for(ll j=i*i;j<=N;j+=2*i)
                sieve[j]=1;
        }
    }
    for(i=3;i<=N;i+=2)
    {
        if(sieve[i]==0)
            prime.push_back(i);
    }

}

vector<ll>factor;
void factorize(ll n)
{
    factor.clear();
    int sqrtn = sqrt(n);
    ll i;
    for(i=0;i<prime.size()&&prime[i]<=sqrtn;i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                n/=prime[i];
                factor.push_back(prime[i]);
            }
            sqrtn=sqrt(n);
        }
    }
    if(n!=1)
    {
        factor.push_back(n);
    }
}


vector<ll>v;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif
    
    primesieve();
    
    ll n;
    cin >> n;
    factorize(n);
    cout << factor.size() << endl;
    for(int i=0; i<factor.size(); i++)
        cout << factor[i] << " " ;
    
    return 0;
}
