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
#define vis(x,...) vi x(__VA_ARGS__)
#define vls(x,...) vl x(__VA_ARGS__)
#define vvis(x,h,...) vvi x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vvl x(h,vl(__VA_ARGS__))
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

vvi g;
vector<bool> vst;
vi route;

void dfs(int cur, int goal) {
    if (cur == goal) {
        fore(r, route) {
            cout << r << ' ';
        }
        exit(0);
    }

    fore(r, g[cur]) {
        if (vst[r]) continue;

        vst[r] = 1;
        route.push_back(r);
        dfs(r, goal);
        route.pop_back();
    }
}

int main() {
    int n, x, y;
    in(n, x, y);
    g.resize(n + 1);

    rep(i, n) {
        int u, v;
        in(u, v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vst.resize(n + 1);
    vst[x] = 1;

    route.push_back(x);
    dfs(x, y);
    return 0;
}
