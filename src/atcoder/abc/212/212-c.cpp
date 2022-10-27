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
using vvi = vector<vi>;
using vvl = vector<vl>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = INT_MAX;


int main(){
    int n,m,ans = INT_MAX;
    cin >> n >> m;
    vi a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    sort(all(a));
    sort(all(b));

    int ca = 0, cb = 0;
    rep(i, n + m - 1){

        chmin(ans, abs(a[ca] - b[cb]));
        if(ca == n - 1){
            ++cb;
            continue;
        }
        if(cb == m - 1){
            ++ca;
            continue;
        }
        
        if(a[ca] > b[cb]) ++cb;
        else ++ca;

    }

    cout << ans;
}