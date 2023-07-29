#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ll;
 
ll mpow(ll x, ll y, ll m) {
    ll res = 1;
    x = x % m;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % m;
        }
        y = y >> 1;
        x = (x * x) % m;
    }
    return res;
}
 
int miller_rabin(ll n, ll a) {
    ll r = 0;
    ll d = n - 1;
    while (d % 2 == 0) {
        r++;
        d = d >> 1;
    }
    ll x = mpow(a, d, n);
    if (x == 1 || x == n - 1) 
        return 1;
    for (int i = 0; i < r - 1; i++) {
        x = mpow(x, 2, n);
        if (x == n - 1) 
            return 1;
    }
    return 0;
    
 
}
 
int isPrime(ll n) {
    ll arr[5] = { 2, 3, 5, 7, 11 };
    if (n <= 1) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 0; i < 5; i++) {
        ll a = arr[i];
        if (n == a) return 1;
        if (!miller_rabin(n, a)) return 0;
    }
    return 1;
 
}
 
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    while (n--) {
        ll a;
        scanf("%lld", &a);
        if(isPrime(2*a+1)) 
            cnt++;
    }
    printf("%d", cnt);
}