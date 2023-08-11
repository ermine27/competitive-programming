/*
考え方
この問題で求めたいのは最後の人がトンネルの外に出る時間だけで、途中の経過や、最後の人が誰かといった情報は必要としない。
2人が同じ位置に来た時に移動方向を変えるという点について、各人の位置の情報を持たなくていいのであれば、
2人がそのまま交差するとみなしても答えに影響はないと言える。
よって求めるべき答えは、東を向いている人の中で一番西側にいる人と、西を向いている人の中で一番東側にいる人のうち、トンネルの外までの距離が遠いほうになる。
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
    int n, l;
    cin >> n >> l;
    int ll = l, rr = 0;
    rep(i, n) {
        int a;
        char b;
        cin >> a >> b;
        if (b == 'E') {
            chmin(ll, a);
        } else {
            chmax(rr, a);
        }
    }

    cout << max(l - ll, rr) << endl;
    return 0;
}
