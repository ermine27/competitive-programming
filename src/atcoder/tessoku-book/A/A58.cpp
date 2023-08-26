/*
セグメント木についての参考

https://algo-logic.info/segment-tree/#
https://www.creativ.xyz/segment-tree-entrance-999/
https://www.youtube.com/watch?v=LjhVy1ZJTMc
*/
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
区間最大値(Range Maximum Query)をセグメント木(SegmentTree)で管理する

memo: ノードは1-indexで持っている
memo: 区間最小値(Range Minimum Query)を管理したい場合はコメントアウトしている3ヶ所に置き換える
*/
template <typename T>
struct RangeMaximumQuery {
    int size;
    vector<int> node;

    RangeMaximumQuery(int n) {
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
            // node[pos] = min(node[pos * 2], node[pos * 2 + 1]);
            node[pos] = max(node[pos * 2], node[pos * 2 + 1]);
        }
    }

    // 区間最大値の取得
    // [a,b) の半開区間で指定する
    int query(int a, int b) { return _querySub(a, b, 1, 1, size + 1); }

    // 区間最大値を取得する
    // [a,b) が求めたい半開区間
    // k:今見ているノードの位置
    // ノードkが表している区間が[l,r)
    int _querySub(int a, int b, int k, int l, int r) {
        // if(r <= a || b <= l) return INF;
        if (r <= a || b <= l)
            return 0;

        if (a <= l && r <= b)
            return node[k];

        int ll = _querySub(a, b, k * 2, l, (l + r) / 2);
        int rr = _querySub(a, b, k * 2 + 1, (l + r) / 2, r);
        // return min(ll, rr);
        return max(ll, rr);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    RangeMaximumQuery<int> rmq(n);

    rep(i, q) {
        int cmd, pos, x, l, r;
        cin >> cmd;
        if (cmd == 1) {
            cin >> pos >> x;
            rmq.set(pos, x);
        }
        if (cmd == 2) {
            cin >> l >> r;
            cout << rmq.query(l, r) << endl;
        }
    }

    return 0;
}
