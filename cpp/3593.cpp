#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    vector<string> word;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        word.push_back(s);
    }
    set<vector<string>> s;
    map<string, set<string>> mp;

    for (auto w : word) {
        for (int i = 0; i <= w.length(); i++) {
            string pfx = w.substr(0, i);
            string sfx = w.substr(i);
            mp[pfx].insert(sfx);
        }
    }
    for (auto cur : mp) {
        vector<string> v(cur.second.begin(), cur.second.end());
        s.insert(v);
    }
    printf("%d", s.size());
}