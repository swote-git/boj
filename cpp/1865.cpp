#include <bits/stdc++.h>
using namespace std;
#define MX 9999999

int grp[1000 + 10];
vector<pair<int ,int>> adj[1010];

int main() {
    
	int t;
	scanf("%d", &t);
	while (t--) {
		int flag = 0;
		int n, m, w;
		scanf("%d %d %d", &n, &m, &w);
		for (int i = 0; i < m; i++) {
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			adj[a - 1].push_back({ b - 1, w });
			adj[b - 1].push_back({ a - 1, w });
		}
		for (int i = 0; i < w; i++) {
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			adj[a - 1].push_back({ b - 1, -w });
		}
		for (int i = 1; i <= n; i++) grp[i] = MX;

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				for (auto it : adj[j]) {
					if (grp[it.first] > grp[j] + it.second) {
						grp[it.first] = grp[j] + it.second;
						if (i == n - 1) flag = 1;
					}
				}
			
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
		for (int i = 0; i < 1010; i++) adj[i].clear();
	}
}