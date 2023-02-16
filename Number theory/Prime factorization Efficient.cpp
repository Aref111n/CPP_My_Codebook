#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;

ll factors[1000000];
void buildfactors() {
	factors[1]=1 ;
	for(int i=2;i<=1000000; i+=2)
		factors[i]=2 ;
	
	for(int i=3; i*i<=1000000; i+=2) {
		if(!factors[i]) {
			for(int j=i; j*j<=1000000; j+=i)
				factors[j] = i ;
		}
	}
}

void getfactors(ll n) {
	if(factors[n]==n) {
		cout << n << endl ;
		return ;
	}
	
	cout << factors[n] << endl ;
	getfactors(n/factors[n]) ;
}

int main() {
	// your code goes here
	ll tc, z=1 ;
	buildfactors() ;
	cin >> tc ;
	while(tc--) {
		ll n ;
		cin >> n ;
		getfactors(n) ;
	}
	return 0;
}
