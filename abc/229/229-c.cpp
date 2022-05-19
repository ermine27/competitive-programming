#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using ll = long long;

int main() {
    int n,w;
    cin >> n >> w;
    vector<pair<ll, int>> ab(n);

    ll ai;
    int bi;
    rep(i,n){
        cin >> ai >> bi;
        ab[i] = make_pair(ai,bi);
    }

    sort(all(ab));
    reverse(all(ab));
    
    ll ans = 0;
    fore(x,ab){
        int wt = min(w, x.second);
        if(wt == 0) break;

        w -= wt;
        ans += x.first * wt;
    }

    cout << ans;
}
