#include <bits/stdc++.h>
using namespace std;

#define INF 9999999
int n,w;
int idp[10010];
int odp[10010];
int dp[10010];

int in[10010];
int out[10010];

int tmpin;
int tmpout;

void clear() {
	memset(idp, 0, sizeof(idp));
	memset(odp, 0, sizeof(odp));
	memset(dp,  0, sizeof(dp));
}

void fill() {
	for(int i=2; i<=n; i++) {
		int in2 =  (in[i-1]+in[i]<=w)  ? 1:2;
		int out2 = (out[i-1]+out[i]<=w)? 1:2;
		int inout2 = (in[i]+out[i]<=w) ? 1:2;
		
		idp[i] = min(dp[i-1]+1, odp[i-1]+in2);
		odp[i] = min(dp[i-1]+1, idp[i-1]+out2);
		dp[i] = min( {dp[i-1]+inout2, dp[i-2]+in2+out2, idp[i]+1, odp[i]+1});
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int ans = INF;
		scanf("%d %d", &n, &w);
		for(int i=1; i<=n; i++) scanf("%d", &in[i]);
		for(int i=1; i<=n; i++) scanf("%d", &out[i]);
		
		tmpin = in[1];
		tmpout = out[1];
		idp[1] = odp[1] = 1;
		dp[1] = (in[1]+out[1]<=w) ? 1:2;
		
		fill();
		ans = min(ans, dp[n]);
		clear();
		
		if(n != 1 && in[1] + in[n] <= w) {
			idp[1] = odp[1] = 1; dp[1] = 2;
			in[1] = INF;
			
			fill();
			ans = min(ans, odp[n]);
			
			in[1] = tmpin;
		}
	
		if(n != 1 && out[1] + out[n] <= w) {
			idp[1] = odp[1] = 1; dp[1] = 2;
			out[1] = INF;
			
			fill();
			ans = min(ans, idp[n]);
			
			out[1] = tmpout;
		}
		
		if(n != 1 && in[1] + in[n] <= w && out[1] + out[n] <= w) {
			idp[1] = odp[1] = 1; dp[1] = 2;
			in[1] = out[1] = INF;
			
			fill();
			ans = min(ans, dp[n-1]);
			
			in[1] = tmpin;
			out[1] = tmpout;
		}
		printf("%d\n", ans);
        clear();
	}
	return 0;
}