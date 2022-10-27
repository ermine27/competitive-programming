#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
#define npos string::npos
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const long long INFLL = 1e18;


int main(){
    int n;
    cin >> n;
    vi x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    set<pii> m;
    int dx,dy;
    rep(i,n-1){
        reps(j,i+1,n){
            dx = x[i] - x[j];
            dy = y[i] - y[j];

            int g = gcd(dx,dy);

            m.insert(make_pair(dx/g, dy/g));
            m.insert(make_pair(-dx/g, -dy/g));
        }
    }
    cout << m.size();
}
