#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PLL;

PLL p[101000];

int CCW(PLL a, PLL b, PLL c) {
	ll val = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
	if (val < 0)
		return -1;
	else if (val > 0)
		return 1;
	else
		return 0;
}

bool cmp (PLL a, PLL b) {
	int tmp = CCW(p[0], a, b);
	if (tmp) 
		return tmp == 1;
	return a.second < b.second || (a.second == b.second && a.first < b.first);
}

int main() {
	int n;
    vector<PLL> s;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &p[i].first, &p[i].second);
		if (p[i].second < p[0].second || (p[i].second == p[0].second && p[i].first < p[0].first))
			swap(p[i], p[0]);
	}
	
	sort(p + 1, p + n, cmp);

    s.push_back(p[0]);
    s.push_back(p[1]);
	for (int i = 2; i < n; i++) {
		while (s.size() >= 2 && CCW(s[s.size() - 2], s.back(), p[i]) < 1) {
			s.pop_back();
		}
		s.push_back(p[i]);
	}
	printf("%d", s.size());
}

