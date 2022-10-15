#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define fore(x,a) for(auto& (x):(a))
using ll = long long;
using vi = vector<int>;


int main(){
    int n,x;
    cin >> n >> x;
    vi a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];

    set<int> dp;
    dp.insert(0);

    rep(i,n){
        set<int> dp2;
        fore(v,dp){
            dp2.insert(v + a[i]);
            dp2.insert(v + b[i]);
        }
        dp = dp2;
    }

    cout << (dp.count(x) ? "Yes" : "No");

    return 0;
}
