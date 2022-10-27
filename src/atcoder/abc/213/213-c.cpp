#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using vi = vector<int>;


vi compress(vi x){
    vi vals = x;

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    rep(i, x.size()){
        x[i] = lower_bound(all(vals), x[i]) - vals.begin();
    }

    return x;
}

int main(){
    int h,w,n;
    cin >> h >> w >> n;    
    vi a(n), b(n), c(n), d(n);
    rep(i,n) cin >> a[i] >> b[i];

    c = compress(a);
    d = compress(b);

    rep(i,n) cout << c[i]+1 << ' ' << d[i]+1 << endl;
}
