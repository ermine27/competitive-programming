/*
参考にした記事

C++ ムーブ セマンティクスと右辺値の概念を初心者向けに
https://qiita.com/seriru13/items/e5953f88fe23e4140687

std::mapまとめ
https://qiita.com/_EnumHack/items/f462042ec99a31881a81

*/

#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define repf(i, n) reps(i, 1, n + 1)
#define sz(x) ((int)(x).size())
using vi = vector<int>;

int main() {
    int n, k;
    cin >> n >> k;

    // キー：表の数、値：山のカード
    map<int, vi> field;
    vi ans(n + 1, -1);

    rep(i, n) {
        int pi;
        cin >> pi;

        auto it = field.lower_bound(pi);

        if (it != field.end()) {
            // キーを割り当て直す際に、単純に代入で行ると配列がコピーされるため、計算量が悪化、TLEする
            // vi t = field[it->first];
            // field.erase(it->first);
            // field[pi] = t;
            // field[pi].push_back(pi);

            // moveを使ってコピーコストを削減する（ムーブセマンティクス）
            field[pi] = move(it->second);
            field.erase(it);

            // [c++17]
            // extractを使って要素の所有権を転送した場合。上記よりこっちのほうが処理は早い
            // auto node = field.extract(it->first);
            // node.key() = pi;
            // field.insert(move(node));
        }

        field[pi].push_back(pi);

        if (sz(field[pi]) == k) {
            rep(j, k) { ans[field[pi][j]] = i + 1; }
            field.erase(pi);
        }
    }

    repf(i, n) cout << ans[i] << endl;

    return 0;
}
