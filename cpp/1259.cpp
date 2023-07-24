#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int n;
    scanf("%d",&n);
    for (int i = 0 ; i < n; i++) {
        int a;
        scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int q;
        scanf("%d", &q);
        printf("%d\n",binary_search(v.begin(),v.end(),q));
    }
}