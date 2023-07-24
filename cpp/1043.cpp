#include <bits/stdc++.h>
using namespace std;

int arr[100];
bool chk[100];
vector<int> v[100];

int find(int p) {
	int r = p, tmp;
	while (r != arr[r]) {
		r = arr[r];
	}
	while (p != r) {
		tmp = arr[p];
		arr[p] = r;
		p = tmp;
	}
	return r;
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)
		return;
	arr[u] = v;
}

int main() {
    int n, m, k, ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    for (int i = 0; i < n; i++) {
        int a = 0;
        scanf("%d", &a);
        chk[a] = 1;
    }
    
    for (int i = 0; i < m; i++) {
        int t, f = 1;
        scanf("%d", &t);
        int p;
        scanf("%d", &p);
        v[i].push_back(p);
        for (int j = 1; j < t; j++) {
            int a;
            scanf("%d", &a);
            if (chk[a]) {
                f = 0; 
                break;
            }
        }
        if (f) ans++;
    }
    printf("%d", ans);
}