#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[100] = {0,1};
    for (int i = 2; i <= 40; i++) 
        arr[i] = arr[i - 1] + arr[i - 2];

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (n == 0) 
            printf("1 0\n");
        else
            printf("%d %d\n", arr[n - 1], arr[n]);
    }
}