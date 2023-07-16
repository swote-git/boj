#include <bits/stdc++.h>
using namespace std;

// 문제 : m / 가장작은 p[i] 값. : 자리수
// 1 번째 자리 수 부터 가장 큰 값 가져가면 됨.

// 관건 : 10^18이라는 큰수의 나눗셈

string cost[11];
string m;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    cin >> m;

    sort(cost, cost + n);
    
}