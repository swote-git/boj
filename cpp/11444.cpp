#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;

unordered_map<ll, ll> f;

ll fib(ll n) {	
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (f.count(n) > 0) return f[n];

	ll m = (n+1) / 2;
	ll tmp1 = fib(m); 
    ll tmp2 = fib(m - 1);

	if (n % 2 == 0) {
		f[n] = ((2LL * tmp2 + tmp1) % MOD * tmp1) % MOD;
		return f[n];
	}
	f[n] = ((tmp1 * tmp1) % MOD + (tmp2 * tmp2) % MOD) % MOD;
	return f[n];
}

int main() {
	ll n;
    scanf("%lld", &n);
    printf("%lld", fib(n));
}