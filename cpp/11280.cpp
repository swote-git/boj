#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2][10010];
int vis[2][10010];
bool fin[2][10010];
stack<int> s;
int cnt = 0, res = 1;

int DFS(int v) {
	int p = ++cnt, f = v < 0;
	int sv = v;
	
	s.push(v);
	
	v = abs(v);
	vis[f][v] = p;
	
	for(int i = 0; i < adj[f][v].size(); i++) {
		int to = adj[f][v][i];
		int t = to < 0;
		
		if(!vis[t][abs(to)]) 
			p = min(p, DFS(to));
		else if(!fin[t][abs(to)])
			p = min(p, vis[t][abs(to)]);
	}
	
	if(p == vis[f][v]) {
		set<int> scc;
		while(!s.empty()) {
			int top = s.top(); s.pop();
			
			fin[top < 0][abs(top)] = 1;
			if(scc.count(abs(top)))
				res = 0;
			if(sv == top)
				break;
			scc.insert(abs(top));
		}
	}
	
	return p;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		int f, t;
		scanf("%d %d", &f, &t);
		
		adj[-t < 0][abs(t)].push_back(f);
		adj[-f < 0][abs(f)].push_back(t);
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(!vis[0][i])
			DFS(i);
		if(!vis[1][i])
			DFS(-i);
	}
	printf("%d", res);
}