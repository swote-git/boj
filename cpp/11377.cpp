#include <bits/stdc++.h>
using namespace std;

#define MAX 2005
#define INF 2147483647
#define MOD 1000000
typedef long long ll;

int n, m, a, b, c, st = 2001, dest = 2002, total = 0, flow[2][MAX][MAX];
vector<int> v[MAX];
queue<int> q;
bool visit[MAX][MAX], tf[MAX];


int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		flow[1][2001][i] = 2;
		v[2001].push_back(i);
		scanf("%d", &a);
		for (int k = 0; k<a; k++) {
			scanf("%d", &b);
			flow[1][i][b + 1000] = 1;
			if (tf[b + 1000] == false) {
				flow[1][b + 1000][2002] = 1;
				v[b + 1000].push_back(2002);
				tf[b + 1000] = true;
			}
			v[i].push_back(b + 1000);
			v[b + 1000].push_back(i);
		}
	}
	while (1) {
		int prev[MAX];
		fill_n(prev, MAX, -1);
		q.push(st);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (auto it : v[cur]) {
				if (prev[it] == -1 && flow[1][cur][it] - flow[0][cur][it]) {
					prev[it] = cur;
					q.push(it);
					if (it == dest)
						break;
				}
			}
		}
		if (prev[dest] == -1)
			break;
		int tmp = dest;
		while (tmp != st) {
			flow[0][prev[tmp]][tmp] += 1;
			flow[0][tmp][prev[tmp]] -= 1;
			tmp = prev[tmp];
		}
		total++;
	}
	printf("%d\n", total);
	return 0;
}