//BISMILLAHIR RAHMANIR RAHIM
//INNALLAHA_MA_AS_SABIRIN
 
 
 
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#define      __                 <<" "<<
#define      loop(m,n)          for(m=0;m<n;m++)
#define      loop1(m,n)         for(m=1;m<=n;m++)
#define      rloop(m,n)         for(m=n-1;m>=0;m--)
#define      say(VAL)           ll VAL; cin >> VAL  
#define      case()             "Case " << z++ << ":"
#define      test_inp()         ll Tc,z=1;cin>>Tc;while(Tc--)
#define      ntest_inp()        for(int Tc=0;Tc<1;Tc++)
#define      len(n)             (long long)((log(n)/log(10))+1.0000000001)
#define      PTF(b)             puts(b?"YES":"NO")
#define      Ptf(b)             puts(b?"Yes":"No")
#define      ptf(b)             puts(b?"yes":"no")
#define      rev                greater<ll>
#define      newline            cout<<endl
#define      quit               return 0
 
 
using namespace std;
using namespace __gnu_pbds;
 
//typedefs
typedef long long ll;
typedef pair<ll,ll> pll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 

//Function prototypes
inline void ls();
inline ll ceill(ll n, ll k=1);
long long maxx(ll=0,ll=0,ll=0,ll=0,ll=0);
long long minn(ll=INT_MAX,ll=INT_MAX,ll=INT_MAX,ll=INT_MAX,ll=INT_MAX);
bool cmp1(pair<ll,ll> i1,pair<ll,ll> i2);
bool cmp2(pair<ll,ll> a, pair<ll,ll> b);
long long eugcd(ll a,ll b);

//constraints...
const ll MX = 100006 ;
const ll mod = 1000000007 ;
 
//Solve here...
struct seg
{
    ll prop, sum ;
};
 
seg tab[4*MX];
ll arr[MX];
 
void init(ll v, ll b, ll e)
{
    if(b==e)
        tab[v].sum = arr[b];
    else
    {
        ll l = v*2 , r = v*2 + 1 ;
        ll m = (b+e)/2 ;
        init(l, b, m);
        init(r, m+1, e);
        tab[v].sum = tab[l].sum + tab[r].sum ;
    } 
}
 
ll query(ll v, ll b, ll e, ll i, ll j, ll c=0)
{
    if(i>e || j<b) return 0;
    if(i<=b && j>=e) return tab[v].sum + c*(e-b+1) ;
    ll l = v*2 , r = v*2 + 1, m = (b+e)/2 ;
    return query(l, b, m, i, j, c + tab[v].prop) + query(r, m+1, e, i, j, c + tab[v].prop);
}
 
void update(ll v, ll b, ll e, ll i, ll j, ll val)
{
    if(j<b || i>e) return; 
    if(b >= i && e <= j)
    {
        tab[v].sum += (e-b+1)*val ;
        tab[v].prop += val ;
        return;
    }
    ll l = v*2 , r = v*2 + 1, m = (b+e)/2 ;
    update(l, b, m, i, j, val);
    update(r, m+1, e, i, j, val);
    tab[v].sum = tab[l].sum + tab[r].sum + (e-b+1)*(tab[v].prop) ;
}

int main()
{
    ls();
    
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
#endif

    ll i,j,k;
    
    test_inp()
    {
        ll n, q;
        cin >> n >> q ;

        loop1(i, n) arr[i] = 0 ;

        init(1, 1, n);

        loop(i, q)
        {
            ll k ;
            cin >> k ;
            if(k==0)
            {
                ll x, y, val;
                cin >> x >> y >> val;
                update(1, 1, n, x, y, val);
            }
            else
            {
                ll x, y ;
                cin >> x >> y ;
                cout << query(1, 1, n, x, y) << endl;
            }
        }

        memset(arr, 0, sizeof arr);
        memset(tab, 0, sizeof tab);
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
ll minn(ll a, ll b, ll c, ll d, ll e)
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
