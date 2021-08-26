//BISMILLAHIR RAHMANIR RAHIM
//INNALLAHA_MA_AS_SABIRIN
//SOTO's
 
#pragma GCC target("popcnt")
 
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
 
 
#define      __                 <<" "<<
#define      loop(m,n)          for(m=0;m<n;m++)
#define      loop1(m,n)         for(m=1;m<=n;m++)
#define      rloop(m,n)         for(m=n-1;m>=0;m--)
#define      case(z)            "Case " << z++ << ": "
#define      test_inp()         ll Tc,l=1;cin>>Tc;while(Tc--)
#define      ntest_inp()        for(int Tc=0;Tc<1;Tc++)
#define      sf(T)              scanf("%lld",&T)
#define      ssf(T)             scanf("%s", T)
#define      pf(T)              printf("%lld",T)
#define      pf2(a,b)           printf("%lld %lld",a,b)
#define      bin_one(n)         __builtin_popcountll(n)
#define      bin_zero(n)        __builtin_ctz(n)
#define      len(n)             (long long)((log(n)/log(10))+1)
#define      PTF(b)             puts(b?"YES":"NO")
#define      Ptf(b)             puts(b?"Yes":"No")
#define      ptf(b)             puts(b?"yes":"no")
#define      newline            cout<<endl
#define      quit               return 0
 
 
using namespace std;
using namespace __gnu_pbds;
 
//typedefs
typedef long long ll;
typedef pair<ll,ll> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//constants
const ll mod=1000000007;
 
//Function prototypes
inline void ls();
long long maxx(ll=0,ll=0,ll=0,ll=0,ll=0);
long long min(ll=INT_MAX,ll=INT_MAX,ll=INT_MAX,ll=INT_MAX,ll=INT_MAX);
bool cmp1(pair<ll,ll> i1,pair<ll,ll> i2);
bool cmp2(pair<ll,ll> a, pair<ll,ll> b);
long long eugcd(ll a,ll b);
inline ll ceill(ll n, ll k=1);
 
 
 
//Solve here...
int main()
{
    ls();
 
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif 
  
    int i,j;
 
    ntest_inp()
    {
        ll n, m;
        cin >> n >> m ;

        set<ll> div ;
        loop(i, n)
        {
            ll x; cin >> x ;

            ll c = 0 ;
            for(j=2; j*j<=x; j++)
            {
                if(x%j==0)
                {
                    c = 1;
                    div.insert(j);
                    div.insert(x/j);
                }
            }

            if(c==0)
                div.insert(x);
        }

        vector<ll>v(m+1);
        set<ll>::iterator it;

        for(it=div.begin(); it!=div.end(); it++)
        {
            if(*it == 1) 
                continue;

            for(i=*it; i<=m; i+=*it)
                v[i] = 1 ;
        }

        vector<ll>ans;
        loop1(i, m)
        {
            if(v[i]==0)
                ans.push_back(i);
        }

        cout << ans.size() << endl;
        loop(i, ans.size())
            cout << ans[i] << endl;

    }
    quit;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
//.......Functions here......
 
//Faster your code
inline void ls()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
//Multiple Maximum
ll maxx(ll a, ll b, ll c, ll d, ll e)
{
    ll ans = a>b ? a : b ;
    ans = ans > c ? ans : c ;
    ans = ans > d ? ans : d ;
    ans = ans > e ? ans : e ;
 
    return ans;
}
//Multiple Minimum
ll min(ll a, ll b, ll c, ll d, ll e)
{
    ll ans = a<b ? a : b ;
    ans = ans < c ? ans : c ;
    ans = ans < d ? ans : d ;
    ans = ans < e ? ans : e ;
 
    return ans;
}
//double sort, both key and value in descending order
//and to make both ascending, use rbegin() and rend()
//priority: key
bool cmp1(pair<ll,ll> i1,pair<ll,ll> i2)
{
    if(i1.first == i2.first)
        return (i1.second> i2.second);
    else
        return (i1.first >i2.first);
}
//double sort, key ascending and value descending
//for vice versa, use rbegin() and rend()
//priority: value
bool cmp2(pair<ll,ll> a, pair<ll,ll> b)
{
    if(a.second!=b.second)
        return (a.second > b.second);
    else
        return (a.first < b.first);
}
//Euclidean gcd
ll eugcd(ll a,ll b)
{
    if(b==0)
        return a;
    ll p=a%b;
    return eugcd(b,p);
}
//ceil
inline ll ceill(ll n, ll k)
{
    return (n/k)+bool(n%k);
}
//......Function over
 
