/*
case3: 焼きなまし法

score: 5088

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

    auto distance = [&](int city1, int city2) {
        return sqrt(pow(x[city1] - x[city2], 2) + pow(y[city1] - y[city2], 2));
    };

    auto calcTotalDistance = [&]() {
        double totalDistance = 0.0;
        rep(i, n - 1) { totalDistance += distance(route[i], route[i + 1]); }
        totalDistance += distance(route[n - 1], route[0]);
        return totalDistance;
    };

    double minDistance = 0.0;

    rep(i, n) {
        route[i] = i;
        minDistance += distance(i, i + 1);
    }
    route[n] = 0;
    minDistance += distance(n - 1, 1);

    rep(i, 200000) {
        int l = rand() % (n - 1) + 1;
        int r = rand() % (n - 1) + 1;
        if (l > r)
            swap(l, r);

        reverse(route.begin() + l, route.begin() + r + 1);

        double newDistance = calcTotalDistance();

        // case2の局所探索法と異なる部分はここからif文までのみ。

        // 温度t：線形に減少する（30→2）
        double t = 30.0 - 28.0 * i / 200000.0;
        // 確率 p = e ^ (-d/t)   eはネイピア数
        double probability = exp(min(0.0, minDistance - newDistance) / t);
        double random = 1.0 * rand() / RAND_MAX;
        if (random < probability) {
            minDistance = newDistance;
        } else {
            reverse(route.begin() + l, route.begin() + r + 1);
        }
    }

    rep(i, n + 1) { cout << route[i] + 1 << endl; }
    cout << endl;
    return 0;
}
