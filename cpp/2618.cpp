#include <bits/stdc++.h>
using namespace std;

int n,w;
vector<pair<int,int>> p;
int dp[1010][1010];
int pdp[1010][1010];

int dist(int a, int b, int f) {
    int ax, ay, bx, by;
    if(f == 1) {
        ax = 1;
        ay = 1;
    }
    else if(f == 2) {
        ax = n;
        ay = n;
    }
    else {
        ax = p[a - 1].first;
        ay = p[a - 1].second;
    }
    bx = p[b - 1].first;
    by = p[b - 1].second;
    return abs(ax - bx) + abs(ay - by);
}

int func(int p1, int p2) {
    if(p1 == w || p2 == w) 
        return 0;

    int tmp1, tmp2, d;

    d = max(p1, p2) + 1;
    if(dp[p1][p2] != -1) 
        return dp[p1][p2];
    if(p1 == 0)
        tmp1 = func(d,p2) + dist(p1, d, 1);
    else
        tmp1 = func(d,p2) + dist(p1, d, 0);
    if(p2 == 0)
        tmp2 = func(p1,d) + dist(p2, d, 2);
    else
        tmp2 = func(p1,d) + dist(p2, d, 0);

    dp[p1][p2] = min(tmp1,tmp2);

    if(tmp1 < tmp2) 
        pdp[p1][p2] = 1;
    else 
        pdp[p1][p2] = 2;
    return min(tmp1,tmp2);
}

int main(){
    scanf("%d%d", &n, &w);
    for (int i = 0; i < w; i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        p.push_back({a, b});
    }

    for (int i = 0; i < 1010; i++)
        for (int j = 0; j < 1010; j++)
            dp[i][j] = pdp[i][j] = -1;

    printf("%d\n", func(0,0));

    int x = 0;
    int y = 0;
    
    for(int i = 0;i < w;i++) {
        printf("%d\n", pdp[x][y]);
        if(pdp[x][y] == 1)
            x = i + 1;
        else
            y = i + 1;
    }
}