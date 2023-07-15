#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

vector<PII> adj[100010];
int n, v[100010];

PII dfs(int t) {
	PII mx = { 0, t };
	for (auto it : adj[t]) {
		if (v[it.second])
			continue;
		v[it.second] = 1;

		PII next = dfs(it.second);
		next.first += it.first;
		if (mx.first < next.first)
			mx = next;
	}
	return mx;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
        int a, b, w;
        scanf("%d", &a);
		while(1) {
            scanf("%d", &b);
            if (b == -1) 
                break;
            scanf("%d", &w);
            adj[b].push_back({ w, a });
            adj[a].push_back({ w, b });
        }
	}
    v[1] = 1;
	PII res = dfs(1);
	memset(v, 0, sizeof(v));
    v[res.second] = 1;
	PII ans = dfs(res.second);
	printf("%d\n", ans.first);
}