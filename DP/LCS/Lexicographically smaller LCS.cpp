/*
This problem is the solution of LightOJ 1110
*/

//BISMILLAHIR RAHMANIR RAHIM
//INNALLAHA_MA_AS_SABIRIN 
#include<bits/stdc++.h>

#define      loop(m,n)          for(m=0;m<n;m++)
#define      loop1(m,n)         for(m=1;m<=n;m++)
#define      rloop(m,n)         for(m=n-1;m>=0;m--)
#define      case()             "Case " << z++ << ": "
#define      test_inp()         ll Tc,z=1;cin>>Tc;while(Tc--)
#define      ntest_inp()        for(int Tc=0;Tc<1;Tc++)
#define      newline            cout<<endl
#define      quit               return 0
 
 
using namespace std;
 
//typedefs
typedef long long ll;
typedef pair<ll,ll> pll;

string dp[106][106] ;

string lcs(string a, string b)
{
    ll n = a.size() ;
    ll m = b.size() ;

    ll i, j;

    loop(i, n+1) dp[i][0] = "" ;
    loop(i, m+1) dp[0][i] = "" ;

    loop1(i, n)
    {
        loop1(j, m)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + a[i-1];
            else
            {
                ll p = dp[i-1][j].size() ;
                ll q = dp[i][j-1].size() ;

                if(p>q)
                    dp[i][j] = dp[i-1][j] ;
                else if(q>p)
                    dp[i][j] = dp[i][j-1] ;
                else
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m] ;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif

    ll i,j,k;
 
    test_inp()
    {
        string a, b;
        cin >> a >> b ;

        string ans = lcs(a, b);
        if(ans.size() == 0)
            cout << case() << ":(" << endl;
        else
            cout << case() << ans << endl;

    }
    quit;
}
