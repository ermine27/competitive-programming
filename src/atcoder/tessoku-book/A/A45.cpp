/*
白(W)、青(B)、赤(R)として、与えられた交換のパターンを以下の６つで表す。

WW -> W
BB -> R
RR -> B
WB -> B
WR -> R
BR -> W

カードが3枚の場合のパターンを全て調べる。
すると、答えがどの順で交換しても一意になることが分かる。

WWW -> WW  -> W
WWB -> WB  -> B
WWR -> WR  -> R
WBB -> BB, WR  -> R
WRR -> RR, WB  -> B
WBR -> BR, WW  --> W
BBB -> RB  --> W
BBR -> RR, BW  --> B
BRR -> WR, BB  --> R
RRR -> RB  --> W

なので、先頭の2枚から順に交換を繰り返していって、残った1枚がCと一致するかを判定する。
計算量はO(N)になるので問題はない。

（公式解説）
公式解説では、白=0、青=1、赤=2と置き換えている。
このように置き換えて、和のmod3を取ると一致することが分かる。

WW (=0+0=0) -> W
BB (=1+1=2) -> R
RR (=2+2=4=1) -> B
WB (=0+1=1) -> B
WR (=0+2=2) -> R
BR (=1+2=3=0) -> W

これより、全てのカードの和のmod3とCを比較することで判定することができる。
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
    char c;
    string s;
    cin >> n >> c >> s;
    queue<char> q;
    rep(i, n) q.push(s[i]);

    while (q.size() > 1) {
        char x, y, z;
        string ss;
        x = q.front();
        q.pop();
        y = q.front();
        q.pop();

        if (x > y)
            swap(x, y);
        ss.push_back(x);
        ss.push_back(y);
        if (ss == "WW" || ss == "BR")
            z = 'W';
        if (ss == "BB" || ss == "RW")
            z = 'R';
        if (ss == "RR" || ss == "BW")
            z = 'B';
        q.push(z);
    }
    cout << (q.front() == c ? "Yes" : "No") << endl;

    return 0;
}

int main2() {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;
    int sum = 0;
    rep(i, n) {
        if (s[i] == 'B')
            sum += 1;
        if (s[i] == 'R')
            sum += 2;
    }

    sum %= 3;
    bool ok = false;
    if (c == 'W' && sum == 0)
        ok = true;
    if (c == 'B' && sum == 1)
        ok = true;
    if (c == 'R' && sum == 2)
        ok = true;

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
