/*
2進数で考える
4を0、7を1に置き換えると分かりやすい
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
    n--;

    vi bs(10, 4);
    int i = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            bs[9 - i] = 7;
        }
        n /= 2;
        i++;
    }

    rep(i, 10) { cout << bs[i]; }
    cout << endl;
    return 0;
}
