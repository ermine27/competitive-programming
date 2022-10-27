#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
    int n,ai,ci = 0;
    cin >> n;
    vi a(n+2);

    rep(i, n){
        cin >> ai;
        ci = (ci + ai) % 360;
        a[i] = ci;
    }
    a[n] = 0;
    a[n+1] = 360;
    sort(all(a));

    int ans = 0;
    rep(i,n+1){
        chmax(ans,a[i+1]-a[i]);
    }

    cout << ans;
}
