//dsu4
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>prime;
ll n=100000000;
bool sieve[100000005];
void primesieve()
{
    ll i;
    sieve[0]=sieve[1]=1;
    prime.push_back(2);
    for(i=4;i<n;i+=2)
        sieve[i]=1;
    ll sq=sqrt(n);
    for(i=3;i<sq;i+=2)
    {
        if(sieve[i]==0)
        {
            for(ll j=i*i;j<=n;j+=2*i)
                sieve[j]=1;
        }
    }
    ll x=1;
    for(i=3;i<=n;i+=2)
    {
        if(sieve[i]==0)
        {
            prime.push_back(i);
        }
    }
}
int main()
{
    primesieve();
    cout << prime.size() << endl;
    //There are 5761455 prime numbers between 1 and 10^8 
}
