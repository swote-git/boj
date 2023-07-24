#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[100010][5] = {0,};
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int r, g, b;
        scanf("%d%d%d",&r, &g, &b);
        
        arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + r;
        arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + g;
        arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + b;
    }
    printf("%d", min(arr[n][0], min(arr[n][1], arr[n][2])));
}