#include <bits/stdc++.h>

using namespace std;

const int INF = 2147483647;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef long long ll;

struct p {
	double x, y, z;
};


int main() {
    while(1) {
        int n;
        scanf("%d", &n);
        if (!n) break;
        vector<p> arr;
        double cx = 0, cy = 0, cz = 0;
        for (int i = 0; i < n; i++) {
            p a;
            scanf("%lf %lf %lf", &a.x, &a.y, &a.z);
            arr.push_back(a);
            cx += a.x;
            cy += a.y;
            cz += a.z;
        }
        cx /= n;
        cy /= n;
        cz /= n;
        double g = 0.1;
        int t = 50000;
        double mx = 0, idx;
        while (t--) {
            mx = 0;
            for (int i = 0; i < n; i++) {
                double dis = (cx - arr[i].x) * (cx - arr[i].x) + (cy - arr[i].y) * (cy - arr[i].y) + (cz - arr[i].z) * (cz - arr[i].z);
                if (mx < dis) {
                    mx = dis;
                    idx = i;
                }
            }
            cx += (arr[idx].x - cx) * g;
            cy += (arr[idx].y - cy) * g;
            cz += (arr[idx].z - cz) * g;
            g *= 0.99999;
        }
    	printf("%.5lf", sqrt(mx));
    }
}