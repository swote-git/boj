#include <bits/stdc++.h>
using namespace std;

vector<int> tree(1 << 22), lazy(1 << 22), arr(1 << 22);

int init(int n, int s, int e) {
	if (s == e) 
		return tree[n] = arr[s];
	else
		return tree[n] = init(n * 2, s, (s + e) / 2) ^ init(n * 2 + 1, (s + e) / 2 + 1, e);
}
void update_lazy(int n, int s, int e) {
	if (!lazy[n])
		return;
	tree[n] ^= lazy[n] * ((e - s + 1) % 2);
	if (s != e) {
		lazy[n * 2] ^= lazy[n];
		lazy[n * 2 + 1] ^= lazy[n];
	}
	lazy[n] = 0;
}
int update(int n, int s, int e, int l, int r, int k) {
	update_lazy(n, s, e);
	if (l > e || r < s) {
		return tree[n];
	}
	if (l <= s && e <= r) {
		lazy[n] ^= k;
		update_lazy(n, s, e);
		return tree[n];
	}
	return tree[n] = update(n * 2, s, (s + e) / 2, l, r, k) ^ update(n * 2 + 1, (s + e) / 2 + 1, e, l, r, k);
}
int sum_xor(int n, int s, int e, int l, int r) {
	update_lazy(n, s, e);
	if (l > e || r < s)
		return 0;
	if (l <= s && e <= r)
		return tree[n];
	return sum_xor(n * 2, s, (s + e) / 2, l, r) ^ sum_xor(n * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	init(1, 0, n - 1);

	scanf("%d", &m);

	while (m--) {
		int t, s, e, k;
		scanf("%d %d %d", &t, &s, &e);
		if (t == 1) {
			scanf("%d", &k);
			update(1, 0, n - 1, s, e, k);
		} 
		else 
			printf("%d\n", sum_xor(1, 0, n - 1, s, e));
	}
}