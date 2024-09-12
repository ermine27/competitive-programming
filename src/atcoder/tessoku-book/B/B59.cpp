/*
A59の応用問題。
区間和(Range Sum Query)をセグメント木(SegmentTree)で管理することで計算量をO(N logN)に抑える

配列segを用意しておき、i=1～nについて、a[i] > a[j] となるjの個数を以下の手順で数える
１．a[j] > a[i+1] となるj(i<j)の個数はseg[a[i]+1]～seg[n]までの合計になるので、
　　この合計値を答えに加算する
２．seg[i] に1を入れる
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

// memo: ノードは1-indexで持っている
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
    int n;
    ll ans = 0;
    cin >> n;

    vi a(n);
    rep(i, n) { cin >> a[i]; }

    RangeSumQuery<int> seg(n);
    rep(i, n) {
        ans += seg.querySum(a[i] + 1, n + 1);
        seg.set(a[i], 1);
    }

    cout << ans << endl;
    return 0;
}
