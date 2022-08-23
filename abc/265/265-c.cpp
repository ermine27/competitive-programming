#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f

#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define _repe1(i,n) for(int i = 1; i <= (int)(n); ++i)
#define _repe2(i,s,n) for(int i = (int)(s); i <= (int)(n); ++i)
#define repe(...) _overload3(__VA_ARGS__, _repe2, _repe1)(__VA_ARGS__)
#define per(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define perf(i,n) for(int i = (int)(n); i >= 1; --i)
#define _fore1(x,a) for(auto& x:a)
#define _fore2(k,v,a) for(auto& [k,v] : a)
#define fore(...) _overload3(__VA_ARGS__, _fore2, _fore1)(__VA_ARGS__)

#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pil = pair<int,ll>;
using mii = map<int,int>;
using mil = map<int,ll>;
#define vis(x,...) vector<int>x(__VA_ARGS__)
#define vls(x,...) vector<ll>x(__VA_ARGS__)
#define vvis(x,h,...) vector<vi>x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vector<vl>x(h,vl(__VA_ARGS__))

template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }

const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    int h, w;
    in(h, w);
    vector<string> g(h);
    rep(i, h) in(g[i]);

    int x = 0, y = 0;
    set<pii> v;
    while (true) {
        if (v.count(make_pair(x, y))) {
            cout << -1 << endl;
            return 0;
        }
        v.insert(make_pair(x, y));

        char c = g[x][y];
        int d;
        if (c == 'U') d = 2;
        if (c == 'D') d = 0;
        if (c == 'L') d = 3;
        if (c == 'R') d = 1;

        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) break;

        x = nx;
        y = ny;
    }

    cout << x + 1 << ' ' << y + 1 << endl;
    return 0;
}
