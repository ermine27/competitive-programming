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
    ll a, b;
    cin >> a >> b;

    auto gcd = [](ll a, ll b) -> ll {
        if (a < b)
            swap(a, b);
        if (a < b)
            swap(a, b);
        while (a % b != 0) {
            ll m = a % b;
            a = b;
            b = m;
        }
        return b;
    };

    // LCM(a,b) = a*b / GCD(a,b)
    cout << a * b / gcd(a, b) << endl;
    return 0;
}
