#include <bits/stdc++.h>
using namespace std;

bool comp(string a, string b) {
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}
int main() {
    int n;
    vector<string> s;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char str[100];
        scanf("%s\n", str);
        s.push_back(str);
    }

    sort(s.begin(), s.end(), comp);
    s.erase(unique(s.begin(),s.end()),s.end());
    
    for (auto it : s) {
        printf("%s\n",it.c_str());
    }
}