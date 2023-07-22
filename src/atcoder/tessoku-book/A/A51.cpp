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
    stack<string> s;

    rep(i, q) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            string x;
            cin >> x;
            s.push(x);
        }
        if (cmd == 2) {
            cout << s.top() << endl;
        }
        if (cmd == 3) {
            s.pop();
        }
    }

    return 0;
}
