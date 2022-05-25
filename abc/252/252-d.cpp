#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using ll = long long;

ll combination3(ll x){
    return x * (x-1) * (x-2) / (1*2*3);
}

ll combination2(ll x){
    return x * (x-1) / (1*2);
}

int main(){
    int n;
    cin >> n;
    map<int,int> m;
    rep(i, n){
        int ai;
        cin >> ai;
        m[ai]++;
    }

    if(m.size() < 3){
        cout << 0;
        return 0;
    }

    ll ans = combination3(n);

    fore(x, m){
        if(x.second >= 3){
            ll cc = combination3(x.second);
            ans -= cc;
        }
        if(x.second >= 2){
            ll cc = combination2(x.second);
            ans -= cc * (n - x.second);
        }
    }

    cout << ans;
}
