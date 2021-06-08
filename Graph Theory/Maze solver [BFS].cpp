/*
This code implements "Lee Algorithm" to solve this problem.
To know more about Lee algorithm: https://en.wikipedia.org/wiki/Lee_algorithm
*/

//BISMILLAHIR RAHMANIR RAHIM
//INNALLAHA_MA_AS_SABIRIN


#pragma GCC target("popcnt")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define      __                 <<" "<<
#define      loop(m,n)          for(m=0;m<n;m++)
#define      loop1(m,n)         for(m=1;m<=n;m++)
#define      rloop(m,n)         for(m=n-1;m>=0;m--)
#define      case()             "Case " << z++ << ": "
#define      test_inp()         ll Tc,z=1;cin>>Tc;while(Tc--)
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

//Knights moves
//{0,-1,-1,-2,-2,2,2,1,1};
//{0,-2,2,-1,1,-1,1,-2,2};

//Function prototypes
inline void ls();
inline ll ceill(ll n, ll k=1);
long long maxx(ll=0,ll=0,ll=0,ll=0,ll=0);
long long min(ll=INT_MAX,ll=INT_MAX,ll=INT_MAX,ll=INT_MAX,ll=INT_MAX);
bool cmp1(pair<ll,ll> i1,pair<ll,ll> i2);
bool cmp2(pair<ll,ll> a, pair<ll,ll> b);
long long eugcd(ll a,ll b);

//Solve here...
vector<char> adj[255];
map<pll, ll> vis;
map<pll, ll> level;
ll n;

void bfs(pll s)
{
    queue<pll>q;
    q.push(s);
    vis[s] = 1 ;
    level[s] = 1;

    while(q.size())
    {
        pll u = q.front() ;
        q.pop();

        ll x = u.first ;
        ll y = u.second ;

        if(x+1< n && adj[x+1][y]!='O' && vis[{x+1, y}]==0)
        {
            vis[{x+1,y}] = 1;
            level[{x+1,y}] = level[u] + 1 ;
            q.push({x+1,y});
        }

        if(y+1< n && adj[x][y+1]!='O' && vis[{x, y+1}]==0)
        {
            vis[{x,y+1}] = 1;
            level[{x,y+1}] = level[u] + 1 ;
            q.push({x,y+1});
        }

        if(x-1 >= 0 && adj[x-1][y]!='O' && vis[{x-1, y}]==0)
        {
            vis[{x-1,y}] = 1;
            level[{x-1,y}] = level[u] + 1 ;
            q.push({x-1,y});
        }

        if(y-1 >= 0 && adj[x][y-1]!='O' && vis[{x, y-1}]==0)
        {
            vis[{x,y-1}] = 1;
            level[{x,y-1}] = level[u] + 1 ;
            q.push({x,y-1});
        }
    }
}

void backtrace(pll d)
{
    ll x = d.first, y = d.second ;

    adj[x][y] = '+' ;

    if(level[d]==1)
        return;

    pll p = {x-1, y} ;
    pll q = {x+1, y} ;
    pll r = {x, y-1} ;
    pll s = {x, y+1} ;

    if(level[p]+1 == level[d] && x-1>=0)
        backtrace(p);
    else if(level[q]+1 == level[d] && x+1<n)
        backtrace(q);
    else if(level[r]+1 == level[d] && y-1>=0)
        backtrace(r);
    else if(level[s]+1 == level[d] && y+1<n)
        backtrace(s);
}


int main()
{
    ls();
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    int i,j;

    ntest_inp()
    {
        cin >> n ;

        pll st, d;

        loop(i, n)
        {
            string s;
            cin >> s ;
            loop(j, s.size())
            {
                adj[i].push_back(s[j]);

                if(s[j] == 'X')
                    st = {i, j} ;
                if(s[j] == '@')
                    d = {i, j} ;
            }
        }

        bfs(st);

        backtrace(d);

        if(level[d]==0)
        {
            cout << "N" << endl;
            return 0;
        }

        cout << "Y" << endl;

        adj[d.first][d.second] = '@' ;

        loop(i, n)
        {
            loop(j, n)
                cout << adj[i][j] ;
            newline;
        }
                
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
