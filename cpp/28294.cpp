#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll arr[100010], arr2[100010];

int main() {
	int n, a;
    ll sum = 0;
    arr[0] = 1, arr2[0] = 1;
	scanf("%d%d", &n, &a);
	
	for (int i = 1; i <= a; i++) {
		arr[i] = (arr[i-1] * n) % MOD;
        arr2[i] =  (arr[i-1] * (n-1)) % MOD;
    }
	// init : (n - 1) * n ^ a
    sum = (arr[a] - arr[a - 1]) % MOD;
	for (int i = 0; i < n; i++) {
        sum += (arr[a-i] - arr[a-i-1]) * arr2[i] % MOD;
        sum %= MOD;

        printf("%d : %d{(%d - %d) * %d}\n", i, (arr[a-i] - arr[a-i-1]) * arr2[i], arr[a-i],arr[a-i-1],arr2[i]);
    }
    sum = (sum * n) % MOD;
    printf("%d",sum);
	return 0;
}