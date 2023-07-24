#include <bits/stdc++.h>
using namespace std;

int n, r, c, e, ans;
void func(int x, int y, int t) {
    if (x == r && y == c) {
        printf("%d\n", ans);
        return;
    }
    if (!((x <= r && r < x + t) && (y <= c && c < y + t))) {
        ans += t * t;
        return;
    }
    func(x, y, t/2);
    func(x, y + t/2, t/2);
    func(x + t/2, y, t/2);
    func(x + t/2, y + t/2, t/2);
}

int main() {
    scanf("%d%d%d",&n,&r,&c);
    func(0,0,(1<<n));
}