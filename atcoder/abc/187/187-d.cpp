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
using pll = pair<ll,ll>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const long long INFLL = 1e18;

bool compareBySecond(pll a, pll b){
    if(a.second == b.second){
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main(){
    int n;
    cin >> n;
    vi a(n);
    vl b(n);
    vector<pll> d(n);

    rep(i, n){
        cin >> a[i] >> b[i];
        d[i] = make_pair(i, 2 * a[i] + b[i]);
    } 

    sort(all(d),compareBySecond);
    reverse(all(d));

    ll takahashi = 0, aoki = 0;
    rep(i,n) aoki += a[i];

    int ans = 0, no;
    while(takahashi <= aoki){
        no = d[ans].first;
        aoki -= a[no];
        takahashi += (a[no] + b[no]);
        ++ans;
    }

    cout << ans;
}