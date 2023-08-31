/*
左上から右下へ順番に1を[1][1]に、2を[2][2]に、、N-1を[N-1][N-1]へと置くことをシミュレーションしていきながら、
必要な操作回数を数えていくと答えが求められた。
各値ごとの最短の操作数は今いる位置と移動させたい位置との絶対値で求まる。

想定解法は以下。
・行と列は独立しているので別々に考えることができる
・行ないし列において、昇順に並べるのに必要な操作回数＝転倒数（反転数）である
・行と列の反転数の和が求める答えになる
なお、入力情報の中で必要な情報は1,2,...Nの位置さえあればいいので、
1～N の位置の行番号と列番号だけを持っておくようにしている。

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

void changeRow(vector<vector<int>>& p, int n, int x) {
    rep(i, n) { swap(p[x][i], p[x + 1][i]); }
}
void changeCol(vector<vector<int>>& p, int n, int x) {
    rep(i, n) { swap(p[i][x], p[i][x + 1]); }
}

int main() {
    int n, ans = 0;
    cin >> n;

    vector<vector<int>> p(n, vector<int>(n, -1));
    rep(i, n) rep(j, n) {
        cin >> p[i][j];
        p[i][j]--;
    }

    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                if (p[i][j] == k) {
                    ans += abs(i - k) + abs(j - k);

                    if (i < k) {
                        for (int t = i; t < k; t++) {
                            changeRow(p, n, t);
                        }
                    }
                    if (i > k) {
                        for (int t = i; t > k; t--) {
                            changeRow(p, n, t - 1);
                        }
                    }
                    if (j < k) {
                        for (int t = j; t < k; t++) {
                            changeCol(p, n, t);
                        }
                    }
                    if (j > k) {
                        for (int t = j; t > k; t--) {
                            changeCol(p, n, t - 1);
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

int main2() {
    int n, p, ans = 0;
    cin >> n;
    vi x(n), y(n);
    rep(i, n) rep(j, n) {
        cin >> p;
        if (p) {
            x[p - 1] = i;
            y[p - 1] = j;
        }
    }

    rep(i, n - 1) {
        for (int j = i + 1; j < n; j++) {
            if (x[i] > x[j])
                ans++;
            if (y[i] > y[j])
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
