// nを減らしていく方法

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 998244353;

int main(){
    ll n, nt, ans = 0;
    int digit = 0;
    cin >> n;

    nt = n;
    while(nt > 0){
        ll ss;
        ll k = 1;

        for(int i = 0; i < digit; ++i) k *= 10;

        if(nt < 10){
            ss = n - k + 1;
        } else {
            ss = 9 * k;
        }

        ss %= mod;

        ans += (ss * (ss + 1)) / 2;

        ans %= mod;
        nt /= 10;
        ++digit;
    }

    cout << ans;

    return 0;
}
