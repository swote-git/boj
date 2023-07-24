#include <bits/stdc++.h>

using namespace std;

const int INF = 2147483647;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef long long ll;


vector<PDD> arr;

int main() {
	int n;
	scanf("%d", &n);
	double cx = 0, cy = 0;
	for (int i = 0; i < n; i++) {
		double a, b;
		scanf("%lf %lf", &a, &b);
		arr.push_back({ a,b });
		cx += a;
		cy += b;
	}
	cx /= n;
	cy /= n;
	double g = 0.1;
	int t = 50000;
	double mx = 0, idx;
	while (t--) {
		mx = 0;
		for (int i = 0; i < n; i++) {
			double dis = (cx - arr[i].first) * (cx - arr[i].first) + (cy - arr[i].second) * (cy - arr[i].second);
			if (mx < dis) {
				mx = dis;
				idx = i;
			}
		}
		cx += (arr[idx].first - cx) * g;
		cy += (arr[idx].second - cy) * g;
		g *= 0.999;
	}
	printf("%.3lf %.3lf\n", cx, cy);
	printf("%.3lf", sqrt(mx));
}