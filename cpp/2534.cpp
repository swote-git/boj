#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MX 300010
typedef long long ll;

int ind1[MX], ind2[MX];
int arr1[MX], arr2[MX], idx[MX];
vector<int> adj1[MX], adj2[MX];

int main() {
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);
    for (int i = 0; i < p; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        adj1[x].push_back(y);
        adj2[y].push_back(x);
        ind1[y]++;
        ind2[x]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    // 정방향
    for (int i = 0; i < k; i++) 
        idx[i] = k - 1 - i;
    for (int i = 0; i < k; i++) 
        if (!ind1[i]) 
            pq.push(i);
    int t = 0;
    while (!pq.empty()) {
        int h = pq.top();
        pq.pop();
        arr1[h] = idx[t++];
        for (auto it : adj1[h]) 
            if (!--ind1[it]) 
                pq.push(it);
    }

    // 역방향
    for (int i = 0; i < k; i++) 
        idx[i] = n - k + i;
    for (int i = 0; i < k; i++) 
        if (!ind2[i]) 
            pq.push(i);
    t = 0;
    while (!pq.empty()) {
        int h = pq.top();
        pq.pop();
        arr2[h] = idx[t++];
        for (auto it : adj2[h]) 
            if (!--ind2[it]) 
                pq.push(it);
    }
    int res = 0;
    for (int i = 0; i < k; i++) {
        res = ((ll)res * n + arr2[k - i - 1] - arr1[k - i - 1] + MOD) % MOD;
    }
    printf("%d", res);
    return 0;
}