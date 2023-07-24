#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    map<string, int> num;
    map<int, string> name;

    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) {
        char str[30];
        scanf("%s\n",str);
        num[str] = i;
        name[i] = str;
    }
    for (int i = 0; i < m; i++) {
        char q[30];
        scanf("%s",q);
        if ('0' <= q[0] && q[0] <= '9') 
            printf("%s\n", name[stoi(q)].c_str());
        else 
            printf("%d\n", num[q]);
    }
}