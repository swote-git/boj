#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10010];
int vis[10010];
bool fin[10010];
stack<int> s;
vector<vector<int>> scc;
int cnt = 0;

int DFS(int v) {
	int p = vis[v] = ++cnt;
	int sv = v;
	
	s.push(v);
	
	vis[v] = p;
	
	for(int i = 0; i < adj[v].size(); i++) {
		if(!vis[adj[v][i]]) 
			p = min(p, DFS(adj[v][i]));
		else if(!fin[adj[v][i]])
			p = min(p, vis[adj[v][i]]);
	}
	
	if(p == vis[v]) {
        vector<int> sc;
		while(!s.empty()) {
			int top = s.top(); s.pop();	
			fin[top] = 1;
            
			sc.push_back(top);
			if(sv == top)
				break;
		}
        sort(sc.begin(), sc.end());
        scc.push_back(sc);
	}
	
	return p;
}

int main() {
	int v, e;
	scanf("%d%d", &v, &e);
	
	for (int i = 0; i < e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}
	
	for(int i = 1; i <= v; i++)
		if(!vis[i])
			DFS(i);
    
    sort(scc.begin(), scc.end(), [&](const auto& a, const auto& b)->bool {
        return a[0] < b[0];
    });

    printf("%d\n", scc.size());

    for (auto sc : scc) {
        for (auto it : sc) 
            printf("%d ", it);
        printf("-1\n");
    }
}