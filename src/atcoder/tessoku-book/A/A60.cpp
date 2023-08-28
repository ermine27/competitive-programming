/*
この問題の考え方

起算日はi<dかつAi>Adを満たす最大のiで求めると定義されている。
dから順に前の日と比較する方法だとTLEするが、毎回順番を見なくても起算日を探すことはできる。
Aを折れ線グラフで表した時、d日目の起算日はd日目から遡ってAk>Alとなるkの部分だけを順番に見ればよくて、
kが定まった後は、kからdの間はd+1日目以降の起算日になることはない。
つまり、Aj>Ak>Al>... の集合だけを持っておけば判定ができることになり、
これはスタックを使えば実現できる。
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
    vi a(n);
    rep(i, n) cin >> a[i];
    stack<pair<int, int>> st;

    rep(i, n) {
        int ans = -1;
        while (!st.empty()) {
            if (st.top().first > a[i]) {
                ans = st.top().second;
                break;
            }
            st.pop();
        }
        cout << ans << ' ';
        st.push({a[i], i + 1});
    }
    cout << endl;

    return 0;
}
