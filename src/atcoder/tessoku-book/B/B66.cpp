/*
UnionFindを使って駅Aiと駅Biが繋がっているかを判定する。
ただ、辺を削除する処理はできない。
これを解決にするには逆順にして最も辺の数が少ない状態から消される辺を足していく。
そうして得られた答えも逆順にすることで求めたい順番で結果を出力できる。
*/

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define all(v) v.begin(), v.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

struct UnionFind {
    vector<int> _parent, _size;

    UnionFind(int n) {
        _parent.resize(n);
        _size.resize(n, 1);
        for (int i = 0; i < n; i++) _parent[i] = i;
    }

    int find(int x) {
        if (_parent[x] == x)
            return x;
        return _parent[x] = find(_parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;
        if (_size[x] < _size[y])
            swap(x, y);
        _parent[y] = x;
        _size[x] += _size[y];

        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return _size[find(x)]; }
};

int main() {
    int n, m, q;
    cin >> n >> m;
    vi a(m), b(m);
    set<int> s;
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    cin >> q;
    vi cmd(q), x(q), u(q), v(q);
    rep(i, q) {
        cin >> cmd[i];
        if (cmd[i] == 1) {
            cin >> x[i];
            x[i]--;
            s.insert(x[i]);
        }
        if (cmd[i] == 2) {
            cin >> u[i] >> v[i];
            u[i]--;
            v[i]--;
        }
    }

    // 初期化（最後の状態）
    UnionFind uf(n);
    rep(i, m) {
        if (s.count(i) == 0) {
            uf.unite(a[i], b[i]);
        }
    }

    reverse(all(cmd));
    reverse(all(x));
    reverse(all(u));
    reverse(all(v));

    vi ans;

    // 以下のように逆順でループすれば前後のreverse処理もなくすことは可能
    // for (int i = q - 1; i >= 0; i--)
    rep(i, q) {
        if (cmd[i] == 1) {
            uf.unite(a[x[i]], b[x[i]]);
        }
        if (cmd[i] == 2) {
            if (uf.same(u[i], v[i])) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
        }
    }

    reverse(all(ans));
    rep(i, (int)ans.size()) { cout << (ans[i] ? "Yes" : "No") << endl; }

    return 0;
}
