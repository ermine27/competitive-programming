#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;

int main(){
    int n,q;
    cin >> n;
    vi s(n);
    rep(i,n) cin >> s[i];
    cin >> q;
    vi t(q);
    rep(i,q) cin >> t[i];

    int ans = 0;
    rep(i,q){
        bool ok = false;
        rep(j,n){
            if(t[i] == s[j]) ok = true;
        }
        if(ok) ++ans;
    }

    cout << ans << endl;
}
