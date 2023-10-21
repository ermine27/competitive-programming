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
    string s;
    cin >> s;
    int len = s.length();
    stack<int> st;
    rep(i, len) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            cout << st.top() + 1 << ' ' << i + 1 << endl;
            st.pop();
        }
    }
    return 0;
}
