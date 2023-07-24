#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

int a1,a2,l,la,lb,sa,sb;
map<int,int> mp;
stack<int> st;
vector<PII> v;

int main(){
    int n, cnt = 0;
    int flag = 1, flag2 = 1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(i == 1 || (flag && b > 0)){
            v.push_back({a,b});
            continue;
        }
        if(flag) sa=a,sb=b;
        flag = 0;

        if((b > 0 && lb < 0) || (b < 0 && lb > 0)){
            if(!flag2) {
                mp[a]=cnt;
                flag2=1;
            }   
            else {
                mp[a]=++cnt;
                flag2=0;
            }
        }
        la=a,lb=b;
    }

    for(auto it : v){
        int a=it.first;
        int b=it.second;

        if((b>0&&lb<0) || (b<0&&lb>0)){
            if(fl) mp[a]=cnt,fl=0;
            else mp[a]=++cnt,fl=1;
        }

        la=a,lb=b;
    }

    if((sb>0&&lb<0) || (sb<0&&lb>0)){
        if(fl) mp[la]=cnt,fl=0;
        else mp[la]=++cnt,fl=1;
    }

    for(auto it=mp.begin();it!=mp.end();it++){
        if(st.empty()){
            st.push(it->second);
            a1++;
            l=it->second;
        }else if(st.top() == it->second){
            if(st.top() == l) a2++;
            st.pop();
        }else{
            st.push(it->second);
            l=it->second;
        }
    }
    printf("%d %d",a1,a2);
}