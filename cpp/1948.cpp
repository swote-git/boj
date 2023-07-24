#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int ind[10010], arr[10010], visited[10010];
vector<PII> adj[10010], badj[10010];


int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        adj[a].push_back({b, w});
        badj[b].push_back({a, w});
        ind[b]++;
    }
    int sv,ev;
    scanf("%d%d", &sv, &ev);

    queue<int> q;
    q.push(sv);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto it : adj[v]) {
            ind[it.first]--;
            if (arr[it.first] < arr[v] + it.second)
                arr[it.first] = arr[v] + it.second;
            if (!ind[it.first]) 
                q.push(it.first);
        }
    }

    int cnt = 0;
    q.push(ev);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        if (visited[v])
            continue;
        
        for (auto it : badj[v]) {
            if (arr[v] == arr[it.first] + it.second) {
                cnt++;
                q.push(it.first);
            }
        }
        visited[v] = 1;
    }
    printf("%d\n%d", arr[ev], cnt);
}