#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define fore(x,a) for(auto& x:a)
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define cout(x) cout<<(x)
#define couts(x) cout<<(x)<<' '
#define coutn(x) cout<<(x)<<endl
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pil = pair<int,ll>;
using mii = map<int,int>;
using mil = map<int,ll>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const long long INFLL = 1e18;

#ifdef LOCAL
#include "../../debug_print.hpp"
#define dbg(...) cout << '(' << __LINE__ << ')' << endl; debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) (static_cast<void>(0))
#endif


int main(){
    int n, m;
    cin >> n >> m;
    vi s(n);
    rep(i, n) cin >> s[i];
    vvi s(n, vi(m));

    return 0;
}
