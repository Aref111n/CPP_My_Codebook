#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;

ll lps[100006];
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

bool kmp(string a, string b)
{
    ll n = a.size() ;
    ll m = b.size() ;

    initlps(b);

    int i = 0, j = 0 ;
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
            return 1;
    }

    return 0 ;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif
    
    string s, t;
    cin >> s >> t ;
    if(kmp(s, t))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

}
