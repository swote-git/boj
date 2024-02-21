#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[200010];
vector<pair<int, int>> v[400010];

int main() {
    int p, f, res = 0;
    scanf("%d%d", &p, &f);

    for (int i = 0; i < p; i++) 
        scanf("%d", &arr[i].first);

    for (int i = 0; i < f; i++) {
        scanf("%d", &arr[p + i].first);
        arr[p + i].second = 1;
    }    
    sort(arr, arr + p + f);

    int t = p + f;
    for (int i = 0; i < p + f; i++) 
        if (arr[i].second)
            v[--t].push_back(arr[i]);
        else
            v[t++].push_back(arr[i]);

    for (int i = 0; i < (p + f) * 2; i++) {
        if (v[i].empty()) continue;
        int sum = 0, mn;
        for (int j = 1; j < v[i].size(); j += 2) 
            sum += v[i][j].first - v[i][j - 1].first;
        mn = sum;
        if (v[i].size() & 1) {
            for (int j = v[i].size() - 1; j > 1; j -= 2) {
                sum += v[i][j].first - v[i][j - 1].first * 2 + v[i][j - 2].first;
                mn = min(mn, sum);
            }
        }
        res += mn;
    }
    printf("%d\n", res);
    return 0;
}