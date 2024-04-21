/*
状態と遷移があるので、グラフの問題に置き換えることができる。
N<=10と小さいので2進数で全ての状態を表現することができ、
ランプのON/OFFは対象のビットを反転させることで遷移が表現できる。
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
    int n, m, a = 0, ai, x, y, z;
    cin >> n >> m;
    rep(i, n) {
        cin >> ai;
        a |= (ai << i);
    }
    vi g(m);
    rep(i, m) {
        cin >> x >> y >> z;
        g[i] |= (1 << (x - 1)) | (1 << (y - 1)) | (1 << (z - 1));
    }

    vi step((1 << n), -1);
    step[a] = 0;
    queue<int> que;
    que.push(a);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        rep(i, m) {
            int nxt = cur ^ g[i];
            if (step[nxt] != -1)
                continue;

            que.push(nxt);
            step[nxt] = step[cur] + 1;
        }
    }

    cout << step[(1 << n) - 1] << endl;
    return 0;
}
