#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f

#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define _repe1(i,n) for(int i = 1; i <= (int)(n); ++i)
#define _repe2(i,s,n) for(int i = (int)(s); i <= (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define repe(...) _overload3(__VA_ARGS__, _repe2, _repe1)(__VA_ARGS__)

using vi = vector<int>;


int main(){
    map<char,int> m = {{'a',1}, {'t',2}, {'c',3}, {'o',4}, {'d',5}, {'e',6}, {'r',7}};
    string s;
    cin >> s;
    vi a(7);
    rep(i,7) a[i] = m[s[i]];

    int ans = 0;
    rep(i,6){
        rep(j,i+1,7){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
                ++ans;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
