#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

/*
区間和(Range Sum Query)をセグメント木(SegmentTree)で管理する

memo: ノードは1-indexで持っている
*/
template <typename T>
struct RangeSumQuery {
    int size;
    vector<int> node;

    RangeSumQuery(int n) {
        size = 1;
        while (size < n) size <<= 1;
        node.assign(size * 2, 0);
        return;
    }

    // 1点更新
    void set(int pos, int val) {
        pos += size - 1;
        node[pos] = val;

        while (pos > 1) {
            pos /= 2;
            node[pos] = node[pos * 2] + node[pos * 2 + 1];
        }
    }

    // 区間和の取得
    // [a,b) の半開区間で指定する
    int querySum(int a, int b) { return _querySumSub(a, b, 1, 1, size + 1); }

    // [a,b) が求めたい半開区間
    // k:今見ているノードの位置
    // kが表している区間が[l,r)
    int _querySumSub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)
            return 0;
        if (a <= l && r <= b)
            return node[k];

        int ll = _querySumSub(a, b, k * 2, l, (l + r) / 2);
        int rr = _querySumSub(a, b, k * 2 + 1, (l + r) / 2, r);
        return ll + rr;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    RangeSumQuery<int> rsq(n);

    rep(i, q) {
        int cmd, pos, x, l, r;
        cin >> cmd;
        if (cmd == 1) {
            cin >> pos >> x;
            rsq.set(pos, x);
        }
        if (cmd == 2) {
            cin >> l >> r;
            cout << rsq.querySum(l, r) << endl;
        }
    }

    return 0;
}
