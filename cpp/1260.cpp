#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1010];
queue<int> que;
int v, e;
int check[1222];

void DFS(int n) {
	check[n] = 1;
	printf("%d ", n);
	for (int it : adj[n]) {
		if (!check[it]) {
			DFS(it);
		}
	}
}

int main() {
	int start;
	scanf("%d %d %d", &v, &e, &start);
	for (int i = 0; i < e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < v; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	DFS(start);
	printf("\n");
	memset(check, 0, sizeof(check));
	que.push(start);
	check[start] = 1;
	while (!que.empty()) {
		int t = que.size();
		for (int i = 0; i < t; i++) {
			int v = que.front();
			que.pop();
			printf("%d ", v);
			for (int it : adj[v]) {
				if (!check[it]) {
					check[it] = 1;
					que.push(it);
				}
			}
		}
	}
}