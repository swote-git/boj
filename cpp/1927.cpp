#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d",&a);
        if (a) {
            pq.push(-a);
        }
        else {
            if (pq.empty()) {
                printf("0\n");
                continue;
            }
            int t = -pq.top();
            pq.pop();
            printf("%d\n",t);
        }
    }
}