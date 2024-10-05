/*
case2: 局所探索法（山登り法）

score: 4776

※乱数の初期化は行ってないので、繰り返し実行しても同じ結果になる
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

int main() {
    int n;
    cin >> n;
    vi x(n), y(n), route(n + 1);
    rep(i, n) { cin >> x[i] >> y[i]; }

    // 2つの都市の距離を計算する
    auto distance = [&](int city1, int city2) {
        return sqrt(pow(x[city1] - x[city2], 2) + pow(y[city1] - y[city2], 2));
    };

    // 経路全体の移動距離を計算する
    auto calcTotalDistance = [&]() {
        double totalDistance = 0.0;
        rep(i, n - 1) { totalDistance += distance(route[i], route[i + 1]); }
        totalDistance += distance(route[n - 1], route[0]);
        return totalDistance;
    };

    double minDistance = 0.0;

    // 初期ルートはとりあえず1→2→3→...→N-1→N→1の順で作る
    rep(i, n) {
        route[i] = i;
        minDistance += distance(i, i + 1);
    }
    route[n] = 0;
    minDistance += distance(n - 1, 1);

    // 局所探索（2-Opt）
    rep(i, 200000) {
        int l = rand() % (n - 1) + 1;
        int r = rand() % (n - 1) + 1;
        if (l > r)
            swap(l, r);

        // 現在のルートのLからRまでを反転して更新
        reverse(route.begin() + l, route.begin() + r + 1);

        double newDistance = calcTotalDistance();
        // 新しいルートで改善すれば最短ルートを更新
        // 改善されなければルートを元に戻す
        if (newDistance < minDistance) {
            minDistance = newDistance;
        } else {
            reverse(route.begin() + l, route.begin() + r + 1);
        }
    }

    rep(i, n + 1) { cout << route[i] + 1 << endl; }
    cout << endl;
    return 0;
}
