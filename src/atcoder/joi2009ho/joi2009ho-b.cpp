#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
#define all(v) v.begin(), v.end()
#define cout(x) cout<<(x)
#define couts(x) cout<<(x)<<' '
#define coutn(x) cout<<(x)<<endl
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;


int main(){
    int d,n,m;
    cin >> d >> n >> m;
    vi di(n+1), ki(m);

    rep(i,n-1) cin >> di[i+1];
    di[n] = d;
    sort(all(di));

    rep(i,m) cin >> ki[i];

    ll ans = 0;

    rep(i,m){
        auto a1 = lower_bound(all(di), ki[i]);
        ans += min(*a1-ki[i], ki[i] - *prev(a1));
        // 以下でも同じ
        // ans += min(*a1-ki[i], ki[i] - *(a1-1));
    }

    coutn(ans);
    return 0;
}
