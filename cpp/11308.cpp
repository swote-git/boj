#include <bits/stdc++.h>
#include <ios>
using namespace std;

#define MV 2000
typedef pair<int, int> PII;
vector<int> adj[MV];
int discov[MV];
int parent[MV];
int low[MV];
vector<PII> edge;
int cnt, flag;

void DFS(int v) {
	discov[v] = ++cnt;
	low[v] = cnt;
	for (int it : adj[v]) {
		if (it == parent[v]) continue; 

		if (discov[it]) {
			low[v] = min(low[v], discov[it]);

            if (discov[v] > discov[it])
                edge.push_back({v, it});
            continue;
		}
        parent[it] = v;

        DFS(it);

        if (low[it] > discov[v])
            flag = 0;

        low[v] = min(low[v], low[it]);
        edge.push_back({v, it});
	}
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int v, e;
        scanf("%d%d", &v, &e);

        for (int i = 0; i < e; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        flag = 1;
        DFS(1);

        if (!flag) {
            printf("NO\n");
        }
        else {
            printf("YES\n");

            for (auto [a,b] : edge) {
                printf("%d %d\n", a, b);
            }
        }
        
        memset(discov, 0, sizeof(discov));
        memset(low, 0, sizeof(low));
        memset(parent, 0, sizeof(parent));
        for (int i = 0; i < 1500; i++)
            adj[i].clear();
        edge.clear();
        cnt = 0;
    }
}