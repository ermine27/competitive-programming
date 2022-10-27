/*
線を消していく方法では実装が大変になる逆順で１つずつ足していき、
最後に答えを反転することで求めたい順での値を取得できる
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
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using mii = map<int,int>;
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

struct UnionFind {
    vi _parent, _size;

    UnionFind(int n) {
        _parent.resize(n);
        _size.resize(n, 1);
        rep(i, n) _parent[i] = i;
    }

    int find(int x) {
        if (_parent[x] == x) return x;
        return _parent[x] = find(_parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return false;
        if (_size[x] < _size[y]) swap(x, y);
        _parent[y] = x;
        _size[x] += _size[y];

        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return _size[find(x)]; }
};

int main() {
    int n, m;
    cin >> n >> m;
    vi a(m), b(m);
    rep(i, m) in(a[i], b[i]);

    vl ans(m);
    ans[0] = 1LL * n * (n - 1) / 2;

    UnionFind u = UnionFind(n + 1);

    reverse(all(a));
    reverse(all(b));

    rep(i, m - 1) {
        if (u.same(a[i], b[i])) {
            ans[i + 1] = ans[i];
        } else {
            ans[i + 1] = ans[i] - 1LL * u.size(a[i]) * u.size(b[i]);
        }

        u.unite(a[i], b[i]);
    }

    reverse(all(ans));

    rep(i, m) out(ans[i]);
    return 0;
}
