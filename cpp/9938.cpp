#include <bits/stdc++.h>
using namespace std;

int arr[300010];
bool chk[300010];
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
int main(void) {
    int n, l;
	scanf("%d%d", &n,&l);
	for (int i = 1; i <= l; i++)
		arr[i] = i;
	for(int i = 1; i <= n; i++) {
		int a, b, f = 0;
		scanf("%d%d",&a, &b);
		if (!chk[a]) {
			chk[a] = f = 1;
			merge(a, b);
		}
		else if (!chk[b]) {
			chk[b] = f = 1;
			merge(b, a);
		}
		else {
			int tmp = find(a);
			if (!chk[tmp]) {
				chk[tmp] = f = 1;
				merge(a, b);
			}
			else {
				tmp = find(b);
				if (!chk[tmp]) {
					chk[tmp] = f = 1;
					merge(b, a);
				}
			}
		}
		printf("%s\n", f ? "LADICA" : "SMECE");
	}
}