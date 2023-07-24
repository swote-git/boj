#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int ind[1010], arr[1010], cost[1010];
		vector<int> adj[1010];
		int n, k, w;
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &cost[i + 1]);
		for (int i = 0; i < k; i++) {
			int a, b, w;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			ind[b]++;
		}
		scanf("%d", &w);

		queue<int> q;
		for (int i = 1; i <= n; i++)
			if (!ind[i]) {
				q.push(i);
				arr[i] = cost[i];
			}

		while(!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto it : adj[v]) {
				ind[it]--;
				if (arr[it] < arr[v] + cost[it])
					arr[it] = arr[v] + cost[it];
				if (!ind[it]) 
					q.push(it);
			}
		}
		printf("%d\n", arr[w]);
		
		memset(arr, 0, sizeof(arr));
		memset(ind, 0, sizeof(ind));
		memset(cost, 0, sizeof(cost));
		for (int i = 0; i < 1002; i++) adj[i].clear();
	}
}