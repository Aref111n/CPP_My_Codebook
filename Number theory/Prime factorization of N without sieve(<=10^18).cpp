//BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<ll, ll> mp;
void factorize(long long n)
{
    int count = 0;
    while ((n % 2)!=1) {
        n/=2;
        count++;
    }

    if (count!=0)
        mp[2] = count;

    for (long long i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count!=0)
            mp[i] = count ;
    }

    if (n > 2)
        mp[n] = 1;
}


vector<ll>v;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif
    
    ll n;
    cin >> n;
    factorize(n);
    
    map<ll, ll>::iterator it;
    for(it=mp.begin(); it!=mp.end(); it++)
        cout << it->first << "^" << it->second << endl; 
    
    return 0;
}
