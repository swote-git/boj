#include <bits/stdc++.h>
using namespace std;

int mp[60][60];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1 ,0};

void func(int x, int y) {
    mp[x][y] = 0;

    for (int i = 0; i < 4; i++) 
        if (mp[x + dx[i]][y + dy[i]] == 1)
            func(x + dx[i],y + dy[i]);
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m, k,ans = 0;
        scanf("%d%d%d", &n, &m, &k);
        
        for (int  i = 0; i < n + 2; i++) {
            mp[0][i] = -1;
            mp[m + 1][i] = -1;
        }
        for (int i = 0; i < m + 2; i++) {
            mp[i][0] = -1;
            mp[i][n + 1] = -1;
        }

        for (int i = 0; i < k; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            mp[y + 1][x + 1] = 1;
        }

        for (int i = 1; i <= m; i++) 
            for (int j = 1; j <= n; j++)
                if (mp[i][j] == 1) {
                    ans++;
                    func(i,j);
                }
        
        printf("%d\n", ans);
        memset(mp, 0, sizeof(mp));
    }
}