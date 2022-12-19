#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[100] ;
ll lis(ll n) {
    if(n==0)
        return 1 ;
    ll mx = 0 ;
    for(int i=0; i<n; i++) {
        if(a[i]<a[n])
            mx = max(mx, lis(i)) ;
    }

    return mx+1 ;
}

int main() {
    ll n ;
    cin >> n ;
    for(int i=0; i<n; i++)
        cin >> a[i] ;
    cout << lis(n-1) << endl ;
    return 0 ;
}
