#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> mp;
    vector<string> s;
    int n, m, cnt = 0;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++) {
        char str[30];
        scanf("%s\n", str);
        mp[str] = 1;
    }
    for (int i = 0; i < m; i++) {
        char q[30];
        scanf("%s\n",q);
        if (mp[q] == 1) 
            s.push_back(q);
    }

    sort(s.begin(), s.end());
    printf("%d\n", s.size());
    for (auto it : s)
        printf("%s", it.c_str());
}