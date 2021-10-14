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
const ll mod1 = 998244353 ;
const double pi = 3.14159265358979323846 ;
 
//Solve here...

vector<pll> adj[MX], adj1[MX];
ll d[MX], d1[MX];
ll n;

void dijsktra(ll v)
{
    ll vis[MX]={0};
    for(int i=1; i<=n; i++) d[i] = 1e18 ;

    d[v] = 0;
    ll u;
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    pq.push({d[v], v});

    while(pq.size())
    {
        u = (pq.top()).second;
        pq.pop();

        if(vis[u]) //Vis required if graph contains loop
            continue;
        vis[u]=1;

        vector<pll>::iterator it;
        for(it=adj[u].begin(); it!=adj[u].end(); it++)
        {
            if(d[it->first] > d[u] + it->second)
            {
                d[it->first] = d[u] + it->second ;
                pq.push({d[it->first], it->first});
            }
        }
    }
}

void dijsktra1(ll v)
{
    ll vis1[MX]={0};
    for(int i=1; i<=n; i++) d1[i] = 1e18 ;

    d1[v] = 0;
    ll u;
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    pq.push({d1[v], v});

    while(pq.size())
    {
        u = (pq.top()).second;
        pq.pop();

        if(vis1[u])
            continue;
        vis1[u]=1;

        vector<pll>::iterator it;
        for(it=adj1[u].begin(); it!=adj1[u].end(); it++)
        {
            if(d1[it->first] > d1[u] + it->second)
            {
                d1[it->first] = d1[u] + it->second ;
                pq.push({d1[it->first], it->first});
            }
        }
    }
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
        cout << case() << endl;
        ll m, x, q;
        cin >> n >> m >> x >> q ;

        loop(i, m)
        {
            ll a, b, w;
            cin >> a >> b >> w ;
            adj[a].push_back({b, w});
            adj1[b].push_back({a, w});
        }       

        dijsktra(x);
        dijsktra1(x);

        loop(i, q)
        {
            ll s, t;
            cin >> s >> t ;
            if(d1[s]+d[t] < 1e18)
                cout << d1[s]+d[t] << endl;
            else
                cout << "Be seeing ya, John" << endl;
        }

        loop1(i, n) adj[i].clear();
        loop1(i, n) adj1[i].clear();
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
