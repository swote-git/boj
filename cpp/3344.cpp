#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
    int f = n % 2;
	if ((!f && n % 6 != 2) || (f && (n - 1) % 6 != 2)) {
		if (f)
            n--;
		for (int i = 1; i <= n / 2; i++)
			printf("%d\n", 2 * i);
		for (int i = 1; i <= n / 2; i++)
			printf("%d\n", 2 * i - 1);
		if (f)
            printf("%d\n", n + 1);
	}

	else if ((!f && n / 6 != 0) || (f && (n - 1) / 6 != 2))	{
		if (f)
            n--;
		for (int i = 1; i <= n / 2; i++)
			printf("%d\n", 1 + (2 * i + n / 2 - 3) % n);
		for (int i = n / 2; i > 0; i--)
			printf("%d\n", n - (2 * i + n / 2 - 3) % n);
		if (f)
            printf("%d\n", n + 1);
	}
}