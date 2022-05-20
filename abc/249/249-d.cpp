#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;


vi divisor(int x){
    vi ans;
    for(int i = 1; i*i <= x; ++i){
        if(x % i == 0){
            ans.push_back(i);
            if(i * i != x){
                ans.push_back(x/i);
            }
        }
    }

    sort(all(ans));
    return ans;
}


int main(){
    int n, ai;
    ll ans = 0;
    cin >> n;
    map<int,int> m;
    rep(i, n){
        cin >> ai;
        m[ai]++;
    }

    fore(x,m){
        int ai = x.first;
        vi d = divisor(ai);

        for(int aj : d){
            int ak = ai / aj;

            if(m.count(aj) == 0 && m.count(ak) == 0){
                continue;
            }

            ll aa = (ll)m[ai] * m[aj] * m[ak];
            ans += aa;
        }
    }
    cout << ans;
    return 0;
}
