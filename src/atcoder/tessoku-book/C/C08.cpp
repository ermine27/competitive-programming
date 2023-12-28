/*
Nがせいぜい1万個なので全探索する
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

// ゼロ埋めの文字列を作成する
string zeroPadding(int n, int len) {
    string s = to_string(n);
    return string(max(0, len - (int)s.length()), '0') + s;
}

int main() {
    set<string> c;
    rep(i, 10000) {
        string ss = zeroPadding(i, 4);
        c.insert(ss);
    }

    int n;
    cin >> n;
    rep(i, n) {
        string s;
        int t;
        cin >> s >> t;
        if (t == 1) {
            cout << s << endl;
            return 0;
        }
        // 該当しないものを消し込む
        // s,tを配列に入れておいて、このループを外側に置いた方が計算量は少ない。
        rep(i, 10000) {
            // 一致する箇所の数を数える
            string s2 = zeroPadding(i, 4);
            int same = 0;
            rep(j, 4) {
                if (s[j] == s2[j])
                    same++;
            }

            // 2等 → 2文字違い・3文字違い・4文字違いを候補から消す
            // 3等 → 0文字違い・1文字違いを候補から消す
            if ((t == 2 && same < 3) || (t == 3 && same >= 3)) {
                c.erase(s2);
            }
        }
    }

    if (c.size() == 1) {
        cout << *c.begin() << endl;
    } else {
        cout << "Can't Solve" << endl;
    }

    return 0;
}
