#include <bits/stdc++.h>
using namespace std;


int arr[60];
int t[60];

int find(int p) {
    int r = p, tmp;
    while(r != arr[r]) {
        r = arr[r];
    }
    while (p != r) {
        tmp = arr[p];
        arr[p] = r;
        p = tmp;
    }
    return r;
}

void Uinon(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)
        arr[a] = b;
}
int main() {
    int n, m, k, ans = 0;
    vector<int> party[60];
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) 
        arr[i] = i;
    for (int i = 0; i < k; i++) {
        int a;
        scanf("%d", &a);
        t[a] = 1;
    }
    for (int i = 0; i < m; i++) {
        int nm, p;
        scanf("%d%d", &nm, &p);
        party[i].push_back(p);
        for (int j = 1; j < nm; j++) {
            int tmp;
            scanf("%d", &tmp);
            party[i].push_back(tmp);
            Uinon(p, tmp);
            p = tmp;
        }
    }
    for (int i = 1; i <= n; i++) 
        if (t[i]) 
            t[find(i)] = 1;
    
    for (int i = 0; i < m; i++) {
        int f = 1;
        for (auto it : party[i]) 
            if (t[find(it)]) {
                f = 0;
                break;
            }
        if (f)
            ans++;
    }
    printf("%d\n", ans);
}