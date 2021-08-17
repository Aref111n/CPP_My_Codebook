//BISMILLAHIR RAHMANIR RAHIM
//INNALLAHA_MA_AS_SABIRIN
 
 
 
#include<bits/stdc++.h>

#define      loop(m,n)          for(m=0;m<n;m++)
#define      loop1(m,n)         for(m=1;m<=n;m++)
#define      rloop(m,n)         for(m=n-1;m>=0;m--)
#define      test_inp()         ll Tc,z=1;cin>>Tc;while(Tc--)
#define      ntest_inp()        for(int Tc=0;Tc<1;Tc++)
#define      newline            cout<<endl
#define      quit               return 0
 
 
using namespace std;
 
//typedefs
typedef long long ll;
typedef pair<ll,ll> pll;
 
//constants
const ll mod = 1000000007;
const ll MX = 100006 ;
 
//Solve here...
ll lps[1000006];
void initlps(string b)
{
    ll m = b.size() ;
    int i = 0 ;
    for(int j=1; j<m; )
    {
        if(b[i] == b[j])
        {
            lps[j] = i+1 ;
            i++, j++ ;
        }
        else
        {
            if(i != 0)
                i = lps[i-1] ;
            else
            {
                lps[j] = 0 ;
                j++;
            }
        }

    }
}

ll kmp(string a, string b)
{
    ll n = a.size() ;
    ll m = b.size() ;

    initlps(b);

    int i = 0, j = 0 , c = 0;
    while(i < n)
    {
        if(a[i] == b[j])
            i++, j++ ;
        else
        {
            if(j)
                j = lps[j-1] ;
            else
                i++ ;
        }

        if(j == m)
        {
            c++;
            j=lps[j-1];
        }
    }

    return c ;
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif

    ll i,j,k;
 
    ntest_inp()
    {
        string s, t;
        cin >> s >> t ;
        cout << kmp(s, t) << endl;

    }
    quit;
}
