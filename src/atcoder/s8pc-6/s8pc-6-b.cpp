#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const long long INFLL = 1e18;


int main(){
    int n;
    cin >> n;
    vl a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    ll ans = INFLL;
    rep(i,n){
        rep(j,n){
            ll start = a[i];
            ll goal = b[j];
            ll dist = 0;
            rep(k,n){
                dist += abs(a[k]-start) + (b[k]-a[k]) + abs(goal-b[k]);
            }
            chmin(ans, dist);
        }
    }

    cout << ans;
}
