#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
using ll = long long;
using vi = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
    int n,k;
    cin >> n >> k;
    vi c(n);
    rep(i, n){
        cin >> c[i];
    }

    map<int,int> m;
    int ans = 0;

    rep(i,n){
        ++m[c[i]];
        if(i >= k){
            int dn = c[i-k];
            --m[dn];
            if(m[dn] == 0) m.erase(dn);
        }

        chmax(ans, (int)m.size());
    }

    cout << ans;
}