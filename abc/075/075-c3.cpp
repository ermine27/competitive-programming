/*
UnionFindを使って解く

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
#define _fore1(x,a) for(auto& x:a)
#define _fore2(k,v,a) for(auto& [k,v] : a)
#define fore(...) _overload3(__VA_ARGS__, _fore2, _fore1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using vi = vector<int>;
using mii = map<int,int>;
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }


struct UnionFind {
    vi rank, parent;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        rep(i, n) parent[i] = i;
    }

    int findRoot(int x){
        if (parent[x] == x) return x;
        return findRoot(parent[x]);
    }

    void unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);

        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
            if (rank[x] == rank[y]) ++rank[y];
        }
    }

    bool same(int x, int y){
        return findRoot(x) == findRoot(y);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vi a(m), b(m);
    rep(i, m) in(a[i], b[i]);

    int ans = 0;
    rep(i, m) {
        UnionFind u = UnionFind(n + 1);
        rep(j, m) {
            if (j == i) continue;

            u.unite(a[j], b[j]);
        }

        mii cnt;
        repe(j, n) {
            int rt = u.findRoot(j);
            cnt[rt]++;
        }

        if (cnt.size() > 1) ++ans;
    }

    out(ans);
    return 0;
}
