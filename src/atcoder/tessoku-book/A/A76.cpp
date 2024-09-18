/*
※注意
DropboxにあるシステムテストケースはAtcoderのジャッジシステムよりテスト数が多い。
このコードでACはするが、Dropboxだけにある 20_max_07 のケースはWAになる。


この問題で使うテクニック
・累積和
・二分探索
・動的計画法

dp[i] = 足場iまで移動する通り数とすると、
  dp[i] = Σdp[j] （jは、L <= Xi - Xj <= R を満たす範囲）
で求まる。
この計算量はO(N^2)であり、TLEする。

LとRを効率的に求めるために二分探索と累積和を使う。
そうすろと計算量はO(N log N)になるので、時間制限内に求めることができる。

[手順]
1. 足場の位置のリスト(pos)を作る
  pos = {0, X1, X2, ... , Xn < W}

2. DPと累積和(cum)の配列を初期化する
  dp[N+2] を用意
  dp[0] = 1
  cum[0] = dp[0]

3. 各位置についてdpを計算する
  3-1. ジャンプ元の位置の範囲を特定する
    pos[i] に到達するためにジャンプできる位置 pos[j] は、以下の条件を満たす。
      L <= pos[i] - pos[j] <= R
    これを pos[j] の範囲が定まるように変形すると、
      pos[i] - R <= pos[j] <= pos[i] - L
    となる。
    posはソート済なので、二分探索で範囲[left, right]を特定する
      left = pos[i] - R 以上の最小のインデックス
      right = pos[i] - L 以下の最大のインデックス
    pos[left]からpos[right]までの位置がジャンプ元となる。

  3-2. dp[i] を計算する
    dp[i] = (cum[right] - cum[left - 1]) % MOD

  3-3. cum[i] を更新する
    cum[i] = (cum[i-1] + dp[i]) % MOD

  4. 結果を出力
    dp[N+1] が東岸に到達する方法の総数

*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
    const int MOD = 1'000'000'007;
    int n, w, l, r;
    cin >> n >> w >> l >> r;
    vector<int> pos(n + 2), dp(n + 2), cum(n + 3);
    rep(i, n) cin >> pos[i + 1];
    // pos[0] = 0;
    pos[n + 1] = w;
    dp[0] = 1;
    // cum[0] = 0;
    cum[1] = dp[0];

    for (int i = 1; i <= n + 1; i++) {
        int left = lower_bound(pos.begin(), pos.end(), pos[i] - r) - pos.begin();
        int right = upper_bound(pos.begin(), pos.end(), pos[i] - l) - pos.begin();
        if (left < right) {
            dp[i] = (cum[right] - cum[left] + MOD) % MOD;
        }
        cum[i + 1] = (cum[i] + dp[i]) % MOD;
    }

    cout << dp[n + 1] << endl;
    return 0;
}
