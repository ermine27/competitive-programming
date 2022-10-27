#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    vi t(n);
    rep(i,n) cin >> s[i] >> t[i];

    set<string> flags;
    int max = 0;
    int ans;
    rep(i,n){
        if(flags.count(s[i]) == 0){
            flags.insert(s[i]);
            if(chmax(max, t[i])){
                ans = i+1;
            }
        }
    }

    cout << ans;

    return 0;
}
