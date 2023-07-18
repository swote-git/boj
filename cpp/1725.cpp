#include <bits/stdc++.h>
using namespace std;

int arr[100010];

int main() 
{
	int n, ans = 0;
    stack<int> s;
    scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
        scanf("%d", arr + i);

	s.push(0);
	for (int i = 1; i <= n + 1; i++) {
		while (!s.empty() && arr[i] < arr[s.top()])
		{
			int t = s.top();
			s.pop();
            int w = i - s.top() - 1;
			ans = max(ans, arr[t] * w);
		}
		s.push(i);
	}
	printf("%d\n", ans);
	
}