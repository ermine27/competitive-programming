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
    ll n;
    cin >> n;
    cout << n / 3 + n / 5 + n / 7 - (n / 15 + n / 21 + n / 35) + n / (3 * 5 * 7) << endl;
    return 0;
}
