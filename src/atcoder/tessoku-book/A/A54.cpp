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
    int q;
    cin >> q;
    map<string, int> m;

    rep(i, q) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            string x;
            int y;
            cin >> x >> y;
            m[x] = y;
        }
        if (cmd == 2) {
            string x;
            cin >> x;
            cout << m[x] << endl;
        }
    }

    return 0;
}
