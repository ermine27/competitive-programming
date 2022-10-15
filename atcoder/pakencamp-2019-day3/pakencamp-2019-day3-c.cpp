#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
    int n, m;
    cin >> n >> m;
    vvi a(n, vector<int>(m));
    rep(i,n) rep(j,m) cin >> a[i][j];

    ll ans = 0;

    rep(i, m-1){
        reps(j,i +1, m){
            ll score = 0;
            rep(k,n){
                score += max(a[k][i], a[k][j]);
            }
            chmax(ans, score);
        }
    }

    cout << ans;
}
