#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main() {
    int n, ai, aj, ak;
    cin >> n;
    ai = aj = 1;

    for (int i = 2; i < n; i++) {
        ak = (ai + aj) % mod;
        ai = aj;
        aj = ak;
    }

    cout << ak << endl;
    return 0;
}
