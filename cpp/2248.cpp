#include <bits/stdc++.h>
using namespace std;

int arr[50][50];

int main() {
    int n, l, k;
    scanf("%d%d%d",&n,&l,&k);
    for (int i = 0; i <=n; i++)
        arr[0][i] = 1;
    int tmp = 0, a, b;
    for (int i = 1; i <= n; i++) 
        for (int j = i; j <= n; j++) 
            arr[i][j] = arr[i][j - 1] + arr[i - 1][j - 1];
        
    for (int i = 1; i <= n; i++)
}