/*
連想配列を使ってDFSで解く
*/

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
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
#define vis(x,...) vi x(__VA_ARGS__)
#define vls(x,...) vl x(__VA_ARGS__)
#define vvis(x,h,...) vvi x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vvl x(h,vl(__VA_ARGS__))
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

const int GMAX = 50;

vvis(g, GMAX + 1, GMAX + 1);
vi vst(GMAX + 1);
int n, m;

void dfs(int x) {
    vst[x]++;

    repe(i, n) {
        if (g[x][i]) {
            if (vst[i]) continue;
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;
    vi a(m), b(m);
    rep(i, m) {
        in(a[i], b[i]);
        g[a[i]][b[i]] = 1;
        g[b[i]][a[i]] = 1;
    }

    int ans = 0;
    rep(i, m) {
        g[a[i]][b[i]] = 0;
        g[b[i]][a[i]] = 0;
        vst.assign(n + 1, 0);

        dfs(1);

        repe(i, n) {
            if (!vst[i]) {
                ans++;
                break;
            }
        }

        g[a[i]][b[i]] = 1;
        g[b[i]][a[i]] = 1;
    }

    out(ans);
    return 0;
}
