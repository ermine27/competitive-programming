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
#define _fore1(x,a) for(auto& x:a)
#define _fore2(k,v,a) for(auto& [k,v] : a)
#define fore(...) _overload3(__VA_ARGS__, _fore2, _fore1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using mii = map<int,int>;
using mll = map<ll,ll>;
#define vis(x,...) vi x(__VA_ARGS__)
#define vls(x,...) vl x(__VA_ARGS__)
#define vvis(x,h,...) vvi x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vvl x(h,vl(__VA_ARGS__))
#define deg2rad(x) (x*M_PI/180.0)
#define rad2deg(x) (x*180.0/M_PI)
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
const int INF = 1.1e9;
const ll INFLL = 4.4e18;
const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

const int CMAX = 20002;
const int ORIGIN = 10001;

int main() {
    int n, x, y;
    in(n, x, y);
    int ai;
    vi ax, ay;
    int a1;
    in(a1);

    rep(i, 1, n) {
        in(ai);
        if (i % 2 == 0) {
            ax.push_back(ai);
        } else {
            ay.push_back(ai);
        }
    }

    vvis(dpx, sz(ax) + 1, CMAX);
    vvis(dpy, sz(ay) + 1, CMAX);
    dpx[0][ORIGIN + a1] = 1;
    dpy[0][ORIGIN] = 1;

    rep(i, sz(ax)) {
        rep(j, CMAX) {
            if (dpx[i][j]) {
                dpx[i + 1][j - ax[i]] += dpx[i][j];
                dpx[i + 1][j + ax[i]] += dpx[i][j];
            }
        }
    }

    rep(i, sz(ay)) {
        rep(j, CMAX) {
            if (dpy[i][j]) {
                dpy[i + 1][j - ay[i]] += dpy[i][j];
                dpy[i + 1][j + ay[i]] += dpy[i][j];
            }
        }
    }

    if (dpx[sz(dpx) - 1][x + ORIGIN] && dpy[sz(dpy) - 1][y + ORIGIN]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
