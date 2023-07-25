#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
typedef pair<int, int> PII;

int d[210][210];
vector<pair<pair<int,int>, int>> edge;

int main() {
    int v, e;
    scanf("%d%d", &v, &e);
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            if (i != j)
                d[i][j] = INF;
    
    for (int i = 0; i < e; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edge.push_back({{a, b}, w});
        d[a][b] = min(d[a][b], w);
        d[b][a] = min(d[b][a], w);
    }

    for (int k = 1; k <= v; k++) 
        for (int i = 1; i <= v; i++) 
            for (int j = 1; j <= v; j++) 
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] +d[k][j];
    double ans = INF;
    for (int i = 1; i <= v; i++) {
        double t = 0;
        for (auto it : edge) {
            int a = it.first.first;
            int b = it.first.second;
            int w = it.second;

            if (!(a == i || b == i)) 
                w += min(d[i][a], d[i][b]);

            double t1 = max(d[i][a], d[i][b]);
            double t2 = (double)(w - t1) / 2;

            if (t2 < 0)
                t2 = 0;
            t = max(t, t1 + t2);
        }
        ans = min(ans, t);
    }
    printf("%.1lf", ans);
}