#include <bits/stdc++.h>
using namespace std;

struct p{
    int x;
    int y;
    int k;
    int cnt;
};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int arr[1010][1010];
int vis[1010][1010];
int vis2[1010][1010];

int main() {
    int n, m;
    scanf("%d%d",&n, &m);
    for (int i = 0; i < n + 2; i++) {
        arr[i][0] = -1;
        arr[i][m + 1] = -1;
    }
    for (int i = 0; i < m + 2; i++) {
        arr[0][i] = -1;
        arr[n + 1][i] = -1;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%1d", &arr[i][j]);
    
    queue<p> q;
    
    q.push({1,1,1, 1});
    vis[1][1] = 1;
    while (!q.empty()) {
        p c = q.front();
        q.pop();
        if (c.x == n && c.y == m) {
            printf("%d\n", c.cnt);
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = c.x + dx[i];
            int ny = c.y + dy[i];
            int& v = c.k?vis[nx][ny]:vis2[nx][ny];
            if (v)
                continue;
            if (arr[nx][ny] == 0) {
                v = 1;
                q.push({nx, ny, c.k, c.cnt + 1});
            }
            if (arr[nx][ny] == 1 && c.k) {
                v = 1;
                q.push({nx, ny, c.k - 1, c.cnt + 1});
            }
        }
    }
    if (!vis[n][m] && !vis2[n][m]) printf("-1");
}