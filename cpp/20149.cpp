#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

int ccW(PII a, PII b, PII c) {
	ll val = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
	if (val < 0)
		return -1;
	else if (val > 0)
		return 1;
	else
		return 0;
}

int main() {
    PII a, b, c, d;

    scanf("%lld%lld", &a.first, &a.second);
    scanf("%lld%lld", &b.first, &b.second);
    scanf("%lld%lld", &c.first, &c.second);
    scanf("%lld%lld", &d.first, &d.second);
    
    int v1 = ccW(a, b, c) * ccW(a, b, d);
    int v2 = ccW(c, d, a) * ccW(c, d, b);
	
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
	
    if (((v1 == 0 && v2 == 0) && !(a <= d && c <= b)) || (v1 > 0 || v2 > 0)) {
        printf("0\n");
        return 0;
	}

    printf("1\n");

    double cx = (a.first * b.second - a.second * b.first) * (c.first - d.first) 
              - (a.first - b.first) * (c.first * d.second - c.second * d.first);
	double cy = (a.first * b.second - a.second * b.first) * (c.second - d.second) 
              - (a.second - b.second) * (c.first * d.second - c.second * d.first);
	double p = (a.first - b.first) * (c.second - d.second) 
             - (a.second - b.second) * (c.first - d.first);

	if (p == 0) {
		if (b == c && a <= c)
            printf("%lld %lld\n", b.first, b.second);
		else if (a == d && c <= a) 
            printf("%lld %lld\n", a.first, a.second);
	}
	else {
        printf("%.9lf %.9lf\n", cx / p, cy / p);
	}
}