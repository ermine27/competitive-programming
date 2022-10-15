/*
連想リストを使ってDFSで解く

M通りの全てについて、i番目の辺だけがない場合のグラフを作っているが、N<=50なので計算量的には問題ない
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
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

vvi g;
vi vst;

void dfs(int x) {
    fore(r, g[x]) {
        if (vst[r]) continue;
        vst[r]++;
        dfs(r);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vi a(m), b(m);
    rep(i, m) in(a[i], b[i]);
    int ans = 0;

    rep(i, m) {
        g.clear();
        vst.clear();
        g.resize(n + 1);
        vst.resize(n + 1);
        rep(j, m) {
            if (i == j) continue;
            g[a[j]].push_back(b[j]);
            g[b[j]].push_back(a[j]);
        }

        int cnt = 0;
        repe(k, n) {
            if (vst[k]) continue;
            vst[k] = 1;
            dfs(k);
            ++cnt;
        }

        if (cnt > 1) ans++;
    }

    out(ans);
    return 0;
}
