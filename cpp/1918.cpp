#include <bits/stdc++.h>
using namespace std;

int main() {
    char str[110];
    stack<char> s;
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            printf("%c",str[i]);
            continue;
        }
        switch (str[i]) {
        case '(':
            s.push(str[i]);
            break;
        case '*':
        case '/':
            while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
                printf("%c", s.top());
                s.pop();
            }
            s.push(str[i]);
            break;
        case '+':
        case '-':
            while (!s.empty() && s.top() != '(') {
                printf("%c", s.top());
                s.pop();
            }
            s.push(str[i]);
            break;
        case ')':
            while (!s.empty() && s.top() != '(') {
                printf("%c", s.top());
                s.pop();
            }
            s.pop();
            break;
        }
    }
    while (!s.empty()) {
        printf("%c", s.top());
        s.pop();
    }
}