#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
int main(){
    int n, d;
    vector<PII> v;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a < b)
            v.push_back({a, b});
        else 
            v.push_back({b, a});
    }

    scanf("%d", &d);
    int ans = 0;
    sort(v.begin(), v.end(), [](const auto& a, const auto& b)->bool {
       if( a.second == b.second )
           return a.first < b.first;
       return a.second < b.second;
    });

    priority_queue<int> PQ;
    for(int i = 0; i < n; i++){
        if( v[i].second - v[i].first > d ) 
            continue;
        PQ.push(-v[i].first);
        while(!PQ.empty() && -PQ.top() < v[i].second - d) 
            PQ.pop();
        ans = max(ans, (int)PQ.size());
    }
    printf("%d", ans);
}